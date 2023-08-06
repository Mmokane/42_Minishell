/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:48:04 by mmokane           #+#    #+#             */
/*   Updated: 2023/08/04 18:32:10 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	quotes_triming(t_token *token)
{
	char	*tmp;

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

void	expand_check(t_token *token, t_env *env)
{
	if ((token->type == DOUBLE) || (token->type == WORD))
	{
		if (ft_strlen(token->content) > 1)
		{
			if (ft_strchr_bool(token->content, '$') == 1)
			{
				token->expanded = 1;
				variable_expander(env, &token->content);
			}
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
		if (*token->content == '$' && ft_strlen(token->content) == 1)
		{
			if (token->next && (token->next->type == DOUBLE
					|| token->next->type == SINGLE))
						token->content = ft_strdup("");
		}
		else if (ft_strlen(token->content) == 2 && token->type == OPERATOR
			&& ft_strcmp(token->content, "<<") == 0)
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

void	variable_expander(t_env *env, char **content)
{
	t_exp	exp;
	int		i;

	exp.str = NULL;
	exp.str2 = NULL;
	exp.join = NULL;
	exp.last_str = NULL;
	i = 0;
	exp.prev = *content;
	while (exp.prev[i] && !acive_expand(exp.prev[i], exp.prev[i + 1]))
		i++;
	if (!exp.prev[i])
		return ;
	if (i)
		exp.str = ft_substr(exp.prev, 0, i);
	exp.j = i + 1 + counter(exp.prev + i + 1);
	exp.str2 = variable_value(env, ft_substr(exp.prev,
				i + 1, exp.j - i - 1));
	exp.join = ft_strjoin(exp.str, exp.str2);
	if (ft_strlen(exp.prev + exp.j))
		exp.last_str = ft_substr(exp.prev, exp.j,
				ft_strlen(exp.prev + exp.j));
	*content = ft_strjoin(exp.join, exp.last_str);
	free_str(exp.last_str, exp.prev, exp.str2);
	variable_expander(env, content);
}
