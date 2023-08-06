/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:13:39 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 21:13:39 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_heredoc(char *line, char *tmp, char *tmp2)
{
	free(tmp);
	free(tmp2);
	free(line);
}

int	delimiter_hr(char *tmp2, char *line)
{
	int	check;

	check = 0;
	if (ft_strcmp(tmp2, line) == 0)
	{
		check = 1;
		free(line);
	}
	return (check);
}

void	open_heredoc(t_redi *red, int fd_heredoc, t_env *env)
{
	char	*line;
	char	*delimiter;
	char	*tmp;
	char	*tmp2;

	delimiter = red->file;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		tmp = ignore_spaces(delimiter);
		tmp2 = delete_quotes(tmp);
		if (delimiter_hr(tmp2, line) == 1)
			break ;
		if (red->must_exp)
			variable_expander(env, &line);
		if (line)
			write(fd_heredoc, line, ft_strlen(line));
		write(fd_heredoc, "\n", 1);
		free_heredoc(line, tmp, tmp2);
	}
	close(fd_heredoc);
}

void	create_heredoc(t_redi *red, t_env *env)
{
	pid_t	pid;
	int		fd_heredoc;
	char	*file_fd;

	file_fd = name_generator();
	red->here_file = ft_strdup(file_fd);
	free(file_fd);
	fd_heredoc = open(red->here_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGINT, SIG_IGN);
		open_heredoc(red, fd_heredoc, env);
		close(fd_heredoc);
		exit(0);
	}
	wait_signal(pid, fd_heredoc);
}

void	ft_heredoc(t_cmd *cmd_list, t_env *env)
{
	t_redi	*red;

	while (cmd_list)
	{
		red = cmd_list->in;
		while (red)
		{
			if (red->type == heredoc)
				create_heredoc(red, env);
			red = red->next;
		}
		cmd_list = cmd_list->next;
	}
}
