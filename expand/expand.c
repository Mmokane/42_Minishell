/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 06:11:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/21 03:33:14 by mmokane          ###   ########.fr       */
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
		token = token->next;
		// if (join_str(&token, tmp) == 0)
		// {
		// 	tmp = token;
		// 	token = token->next;
		// 	printf("content : |%s|\n", tmp->content);
		// 	printf("content : |%s|\n", token->content);
		// }
	}

}


