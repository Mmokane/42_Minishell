/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:15:40 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/26 15:59:45 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	acive_expand(int curr, int next)
{
	if (curr == '$' && (!(!ft_isalnum(next) && next != '_')
			|| next == '?'))
		return (1);
	return (0);
}

void	free_str(char *str1, char *str2, char *str3)
{
	if (str1)
		free(str1);
	free(str2);
	free(str3);
}

char	*variable_value(t_env *env, char *key)
{
	// char	*s;

	// if (*key == '?')
	// {
	// 	free(key);
	// 	s = ft_itoa(g_exec.g_exit_status);
	// 	// g_exec.g_exit_status = 0;
	// 	return (s);
	// }
	while (env && ft_strcmp(env->keyword, key) != 0)
		env = env->next;
	if (env && ft_strcmp(env->keyword, key) == 0)
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

int	words_joiners(t_token **token, t_token *tmp)
{
	if ((*token)->type == PIPE || (*token)->type == OPERATOR
		|| (*token)->type == SPACE || !tmp || tmp->type == PIPE
		|| tmp->type == OPERATOR || tmp->type == SPACE)
		return (1);
	else
	{
		tmp->content = ft_strjoin(tmp->content, (*token)->content);
		tmp->next = (*token)->next;
		clear(*token);
		*token = tmp->next;
		return (0);
	}
}
