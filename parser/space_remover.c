/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:53:21 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/20 06:07:16 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_remove(t_token *tmp, t_token **curr, t_token **token)
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
			ft_remove(tmp, &tok, token);
		}
		else
		{
			tmp = tok;
			tok = tok->next;
		}
	}
}

// void	ft_lstdelone_t(t_token *lst)
// {
// 	if (lst)
// 	{
// 		if (lst->content)
// 			free(lst->content);
// 		free(lst);
// 	}
// }

// void	ft_lstclear_t(t_token **lst)
// {
// 	t_token	*tmp;
// 	t_token	*p;

// 	if (!lst)
// 		return ;
// 	p = *lst;
// 	while (p)
// 	{
// 		tmp = p->next;
// 		ft_lstdelone_t(p);
// 		p = tmp;
// 	}
// 	*lst = NULL;
// }

// void	clear_token(t_token **list)
// {
// 	t_token *tmp;
// 	t_token *tmp2;

// 	if (!list)
// 		return;	
// 	tmp2 = *list;
// 	while (tmp2)
// 	{
// 		tmp = tmp2->next;
// 		if (tmp2->content)
// 			free(tmp2->content);
// 		free(tmp);
// 		tmp2 = tmp;
// 	}
	