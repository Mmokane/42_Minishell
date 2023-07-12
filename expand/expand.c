/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:13:27 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/12 07:33:57 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



void	expander(t_token **token, t_env *env, t_token *joiner)
{
	t_token *tmp;
	
	tmp = NULL;
	quotes_triming(*token);
	while(joiner)
	{
		expand_check(joiner, env);
	}
}
void	handler_expand(t_token **token, t_env *env, t_token *tok)
{
	t_token	*tmp;

	//(void)env;
	///(void)token;
	tmp = NULL;
	trim_quotes(*token);
	here_doc_exp(*token);
	while (tok)
	{
		check_exp(tok, env);
		// check_tokens(tok);
		if (join_str(&tok, tmp) == 0)
		{
			tmp = tok;
			tok = tok->next;
		}
	}
}


