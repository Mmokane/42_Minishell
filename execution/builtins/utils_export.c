/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:15:09 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 21:09:51 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	charsrch(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*take_keyword(char *keyword, int *check)
{
	int		i;

	i = 0;
	while (keyword[i] && keyword[i] != '=' && keyword[i] != '+')
		i++;
	if (keyword[i] == '+')
		*(check) = 1;
	else if (keyword[i] == '=')
		*(check) = 2;
	return (ft_substr(keyword, 0, i));
}

char	*take_value(char *value)
{
	int	i;

	i = 0;
	while (value[i] && value[i] != '=')
		i++;
	if (!value[i])
		return (ft_strdup(""));
	return (ft_substr(value, i + 1, ft_strlen(value)));
}

void	append_value(t_env *env, char *key, char *value)
{
	while (ft_strcmp(env->keyword, key))
		env = env->next;
	env->value = ft_strjoin(env->value, value);
	free(value);
	free(key);
	return ;
}

void	replace_value(t_env *env, char *key, char *value)
{
	while (ft_strcmp(env->keyword, key))
		env = env->next;
	free(key);
	free(env->value);
	env->value = value;
}
