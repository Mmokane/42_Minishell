/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:48:04 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/18 08:19:17 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	quotes_triming(t_token *token)
{
	char *tmp;

	while (token)
	{
		tmp = token->content;
		if (token->type == DOUBLE)
		{
			token->content = ft_strtrim(token->content, "\"");
			free(tmp);
		}
		if (token->type == SINGLE)
		{
			token->content = ft_strtrim(token->content, "\'");
			free(tmp);
		}
		token = token->next;
	}
}
int	exp_here(int curr, int next)
{
	if (curr == '$' && next == '?') // this will give us the exit status
		return (1);
	if (curr == '$' && !must_expand(next)) // this will check for the $ or other nums
		return (1);
	return (0);
}

void	expand_check(t_token *token, t_env *env)
{
	if ((token->type == DOUBLE) || (token->type == WORD))
	{
		if (ft_strlen(token->content) > 1)
		{
			if (*(token->content) == '$')
				token->expanded = 1;
			variable_expander(env, &token->content);
		}
	}	
}

void	expand_type(t_token *token)
{
	if (token->type == WORD)
		token->type = INSIDE_EXP;
	else
		token->type = SINGLE;
}
void	heredoc_expand(t_token *token)
{
	while (token)	
	{
		if (*token->content == '$')
		{
			if (token->next && (token->next->type == DOUBLE
				|| token->next->type == SINGLE))
					token->content = ft_strdup(""); // we are deleting the $
		}
		else if (ft_strlen(token->content) == 2 && token->type == OPERATOR
			&& ft_strcmp(token->content, "<<"))
		{
			if (token->next && token->next->type == SPACE)
			{
				if (token->next->next && token->next->next->type != PIPE
					&& token->next->next->type != OPERATOR)
						expand_type(token->next->next);
			}
			else if (token->next && token->next->type != PIPE
				&& token->next->type != OPERATOR)
						expand_type(token->next);
		}
		token = token->next;
	}
}
void	expand_var(t_env *env, char **content)
{
	char *str;
	char *str1;
	char *join;
	char *last_str;
	int i;
	int j;
	char *prev;

	str = NULL;
	str1 = NULL;
	join = NULL;
	last_str = NULL;
	i = 0;
	prev = *content;
	while (prev[i] && !exp_here(prev[i],prev[i + 1]))
		i++;
	if (!prev[i] || !prev[i + 1])
		return ;
	if (i)
		str = ft_substr(prev, 0, i);
	j = i + 1 + count(prev + i + 1);
	str1 = get_value_of_exp(env, ft_substr(prev, i + 1, j - i - 1));
	join = ft_strjoin(str, str1);
	if (ft_strlen(prev + j))
		last_str = ft_substr(prev, j, ft_strlen(prev + j));
	*content = ft_strjoin(join, last_str);
	ft_free_2(last_str, prev, str1);
	expand_var(env, content);
}
