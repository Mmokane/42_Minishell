/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:21:42 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 22:44:45 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_and_old_pwd(t_env *env, char *old_pwd, char *current_pwd)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp("OLDPWD", tmp->keyword) == 0)
		{
			free(tmp->value);
			tmp->value = old_pwd;
		}
		if (ft_strcmp("PWD", tmp->keyword) == 0)
		{
			free(tmp->value);
			tmp->value = current_pwd;
		}
		tmp = tmp->next;
	}
}

int	get_env(t_env *env)
{
	char	*home;

	home = env_search(&env);
	if (!home)
	{
		ft_putstr_fd("HOME not sett\n", 2);
		g_exit_status = 1;
		return (g_exit_status);
	}
	if (chdir(home) == 0)
		g_exit_status = 0;
	else
	{
		ft_putstr_fd("HOME not set\n", 2);
		g_exit_status = 1;
		return (g_exit_status);
	}
	return (g_exit_status);
}

int	ft_cd(char **av, t_env *env)
{
	char	*old_pwd;
	char	*current_pwd;
	char	*buf;
	t_env	*tmp;

	tmp = env;
	buf = NULL;
	old_pwd = getcwd(buf, 0);
	free(buf);
	if (av[1] == NULL || av[1][0] == '\0')
		get_env(env);
	else if (chdir(av[1]) == 0)
	{
		current_pwd = getcwd(buf, 0);
		pwd_and_old_pwd(env, old_pwd, current_pwd);
		g_exit_status = 0;
		return (g_exit_status);
	}
	else
	{
		perror("");
		g_exit_status = 1;
	}
	return (g_exit_status);
}
