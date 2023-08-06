/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:46:17 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 20:48:48 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_msg(t_cmd *cmd_list)
{
	ft_putstr_fd("minishell : ", 2);
	write (2, cmd_list->cmd[0], ft_strlen(cmd_list->cmd[0]));
	write (2, ": command not found\n", 20);
	g_exit_status = 127;
	exit (g_exit_status);
}

void	error_msg2(t_cmd *cmd_list)
{
	ft_putstr_fd("minishell : ", 2);
	write (2, cmd_list->cmd[0], ft_strlen(cmd_list->cmd[0]));
	write (2, " : Is a directory\n", 18);
	g_exit_status = 126;
	exit (g_exit_status);
}

char	*find_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*path;
	char	*saver_path;

	i = 0;
	while (paths[i])
	{
		if (access(cmd, F_OK) == -1)
		{
			saver_path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(saver_path, cmd);
			if (access(path, F_OK) == 0)
				return (path);
			i++;
		}
		else
			return (cmd);
	}
	return (NULL);
}

char	*check_path_env(char *cmd, char **env)
{
	int		i;
	char	**paths;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH"))
			break ;
		i++;
	}
	if (env[i])
	{
		paths = ft_split(env[i] + 5, ':');
		return (find_cmd_path(cmd, paths));
	}
	write (2, cmd, ft_strlen(cmd));
	write (2, " : No such file or directory\n", 30);
	exit (1);
}

void	exec_cmds(t_cmd *cmd_list, t_env **env)
{
	char	*path;
	char	**envp;

	envp = env_to_array(*env);
	if (!cmd_list->cmd)
	{
		g_exit_status = 0;
		exit (g_exit_status);
	}
	else
	{
		if ((cmd_list->cmd[0][0] == '.' && cmd_list->cmd[0][1] == '/')
			|| cmd_list->cmd[0][0] == '/')
		{
			path = cmd_list->cmd[0];
			if (opendir(path))
				error_msg2(cmd_list);
		}
		else
			path = check_path_env(cmd_list->cmd[0], envp);
		if (execve(path, cmd_list->cmd, envp))
			error_msg(cmd_list);
	}
}
