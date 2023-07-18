/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:48:04 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/18 03:52:46 by mmokane          ###   ########.fr       */
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
void	variable_expander()