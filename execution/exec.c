/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:13:17 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 21:13:17 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	chaild_p(int fd_in, int *fd, t_cmd *cmd_list, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		dup_fds(fd, fd_in);
		if (fd[1] > 2)
			close(fd[1]);
		redirections(cmd_list);
		if (cmd_list->cmd && check_if_builtins(cmd_list))
		{
			exec_builtins(cmd_list, env);
			exit (0);
		}
		else
			exec_cmds(cmd_list, &env);
	}
	return (0);
}

void	norm_exec(t_cmd *cmd_list, t_env *env)
{
	if (cmd_list->cmd && check_if_builtins(cmd_list))
	{
		exec_builtins(cmd_list, env);
		exit (0);
	}
	else
		exec_cmds(cmd_list, &env);
}

void	last_cmd(t_cmd *cmd_list, int fd_in, int *fd, t_env *env)
{
	pid_t	pid;

	if (fd_in == 0 && !cmd_list->in && !cmd_list->out && cmd_list->cmd)
	{
		if (check_if_builtins(cmd_list))
		{
			exec_builtins(cmd_list, env);
			g_exit_status = 0;
			return ;
		}
	}
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (fd_in != STDIN_FILENO)
			my_dup(fd_in, STDIN_FILENO);
		if (fd[1] > 2)
			close (fd[1]);
		redirections(cmd_list);
		norm_exec(cmd_list, env);
	}
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	return ;
}

void	parent_p(void)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
	}
}

void	exec(t_cmd *cmd_list, t_env *env)
{
	int	fd[2];
	int	fd_in;

	if (cmd_list)
	{
		fd_in = STDIN_FILENO;
		while (cmd_list->next)
		{
			pipe(fd);
			chaild_p(fd_in, fd, cmd_list, env);
			close_fds(fd, fd_in);
			fd_in = fd[0];
			cmd_list = cmd_list->next;
		}
		last_cmd(cmd_list, fd_in, fd, env);
		parent_p();
	}
}
