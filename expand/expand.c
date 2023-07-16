/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 06:11:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/16 04:12:31 by mmokane          ###   ########.fr       */
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
	// while (token)
	// {
	// 	printf("type : %d\n", token->type);
	// 	token = token->next;
	// }
	// while (token)
	// {
	// 	check_exp(token, env);
	// 	// check_tokens(tok);
	// 	if (join_str(&token, tmp) == 0)
	// 	{
	// 		tmp = token;
	// 		token = token->next;
	// 	}
	// }
}