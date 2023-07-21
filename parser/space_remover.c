/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:53:21 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/21 01:31:26 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cleaner(t_token *tmp, t_token **curr, t_token **token)
{
	t_token	*exp;

	if (!tmp)
	{
		*token = (*curr)->next;
		clear(*curr); // 
		(*curr) = NULL;
	}
	else
	{
		exp = (*curr)->next;
		clear(*curr);
		
		tmp->next = exp;
		*curr = exp;
	}
}

void	space_remover(t_token **token, t_token *tok)
{
	t_token	*tmp;

	tmp = NULL;
	while (tok)
	{
		if (tok->type == SPACE)
		{
			cleaner(tmp, &tok, token);
		}
		else
		{
			tmp = tok;
			tok = tok->next;
		}
	}
}

	