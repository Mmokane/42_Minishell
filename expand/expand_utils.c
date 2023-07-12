/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 04:43:02 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/12 08:13:11 by mmokane          ###   ########.fr       */
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
void	expand_check(t_token *tok, t_env *env)
{
	(void)env;
	if ((tok->type == DOUBLE || tok->type == WORD)
		&& ft_strlen(tok->content) > 1)
	{
		if (*(tok->content) == '$')
			tok->expanded = 1;
		expand_var(env, &tok->content);
	}
}