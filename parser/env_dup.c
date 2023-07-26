/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 02:01:25 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/26 05:38:40 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	arg_checker(int ac, t_env **dup_env, char **env)
{
	if (ac != 1)
	{
		exit(1);
	}
	env_parsing(env, dup_env);
}

void	*env_parsing(char **env, t_env **env_v2)
{
	int	i;
	int	c;

	i = 0;
	c = '=';
	if (!env || !*env)
	{
		return (NULL);
	}
	while (*env)
	{
		i = 0;
		while ((*env)[i])
		{
			if ((*env)[i] == c)
			{
				add_tolast_env(env_v2, new_env_node(ft_substr(*env, 0, i),
						ft_substr(*env, i + 1, ft_strlen(*env) - i), 1));
				break ;
			}
			i++;
		}
		env++;
	}
	return (env_v2);
}

void	cmd_start(t_cmd *cmd)
{
	cmd->cmd = NULL;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->pipe = 0;
}
