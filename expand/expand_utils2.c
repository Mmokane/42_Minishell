/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:15:40 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/19 02:33:37 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*variable_value(t_env *env, char *key)
{
	char	*s;

	if (*key == '?')
	{
		free(key);
		s = ft_itoa(g_exec.g_exit_status);
		g_exec.g_exit_status = 0;
		return (s);
	}
	while (env && ft_strcmp(env->key, key) != 0)
		env = env->next;
	if (env && ft_strcmp(env->key, key) == 0)
	{
		free(key);
		return (ft_strdup(env->value));
	}
	free(key);
	return (NULL);
}

int	counter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) || str[i] == '?')
		return (1);
	while (str[i] && (!(!ft_isalnum(str[i]) && str[i] != '_')))
		i++;
	return (i);
}