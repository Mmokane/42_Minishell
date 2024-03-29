/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 06:11:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/08/04 01:43:44 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expander(t_token **tokens, t_env *env, t_token *token)
{
	t_token	*tmp;

	(void)env;
	(void)token;
	tmp = NULL;
	quotes_triming(*tokens);
	heredoc_expand(*tokens);
	while (token)
	{
		expand_check(token, env);
		if (words_joiners(&token, tmp) != 0)
		{
			tmp = token;
			token = token->next;
		}
	}
}
