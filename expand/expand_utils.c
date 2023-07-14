/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:48:04 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/14 06:42:49 by mmokane          ###   ########.fr       */
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
// void	here_doc_exp(t_token *token)
// {
// 	while (token)
// 	{
// 		if (*token->content == '$' && ft_strlen(token->content) == 1)
// 		{
// 			if (token->next && (token->next->type == DOUBLE
// 					|| token->next->type == SINGLE))
// 				token->content = ft_strdup("");
// 		}
// 		else if (ft_strlen(token->content) == 2 && token->type == OPERATOR
// 			&& ft_strcmp(token->content, "<<") == 0)
// 		{
// 			if (token->next && token->next->type == SPACE)
// 			{
// 				if (token->next->next && token->next->next->type != PIPE
// 					&& token->next->next->type != OPERATOR)
// 					set_type(token->next->next);
// 			}
// 			else if (token->next && token->next->type != PIPE
// 				&& token->next->type != OPERATOR)
// 				set_type(token->next);
// 		}
// 		token = token->next;
// 	}
// }
