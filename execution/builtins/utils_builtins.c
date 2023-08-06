/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:46:52 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 02:13:45 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	int		len1;
	int		len2;
	int		len3;
	char	*strs;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	strs = (char *)malloc(len1 + len2 + len3 + 1);
	if (!strs)
		return (NULL);
	ft_strcpy(strs, s1);
	ft_strcat(strs, s2);
	ft_strcat(strs, s3);
	return (strs);
}

int	check_if_builtins(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd->cmd[0], "echo") || (!ft_strcmp(cmd->cmd[0], "cd"))
		|| (!ft_strcmp(cmd->cmd[0], "pwd"))
		|| (!ft_strcmp(cmd->cmd[0], "export"))
		|| (!ft_strcmp(cmd->cmd[0], "unset"))
		|| (!ft_strcmp(cmd->cmd[0], "env"))
		|| (!ft_strcmp(cmd->cmd[0], "exit")))
		return (1);
	return (0);
}

void	exec_builtins(t_cmd *cmd_list, t_env *env)
{
	if (!cmd_list->cmd)
		return ;
	if (!ft_strcmp(cmd_list->cmd[0], "echo"))
		ft_echo(cmd_list->cmd);
	else if (!ft_strcmp(cmd_list->cmd[0], "cd"))
		ft_cd(cmd_list->cmd, env);
	else if (!ft_strcmp(cmd_list->cmd[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(cmd_list->cmd[0], "export"))
		ft_export(cmd_list, env);
	else if (!ft_strcmp(cmd_list->cmd[0], "unset"))
		ft_unset(cmd_list, env);
	else if (!ft_strcmp(cmd_list->cmd[0], "env"))
		ft_env(env, cmd_list->cmd);
	else if (!ft_strcmp(cmd_list->cmd[0], "exit"))
		ft_exit(cmd_list);
	else
		return ;
}

char	**env_to_array(t_env *env)
{
	char		**envp;
	int			i;
	int			j;
	t_env		*tmp;

	i = 0;
	j = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	envp = malloc(sizeof(char *) * (i + 1));
	tmp = env;
	while (env)
	{
		envp[j] = ft_strjoin3(env->keyword, "=", env->value);
		j++;
		env = env->next;
	}
	envp[j] = NULL;
	return (envp);
}
