  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:56:33 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/09 03:30:53 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// create a new token_node
t_token *new_token_node(char * content)
{
	t_token *new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->content = content;
	new_token->type = token_type(content);// create it;
	new_token->next = NULL;
	return (new_token);
}
// get the last node 
t_token *last_token_node(t_token *list)
{
	if (!list)
		return (NULL);
	while(list->next)
		list = list->next;
	return (list);
}
// add a token to last node
void add_tolast_node(t_token **list, t_token *new_token)
{
	t_token *last;

	if (!*list)//
	{
		*list = new_token;
		return ;
	}
	last = last_token_node(*list);
	last->next = new_token;
}

void	clear(t_token *list)
{
	if (list)
	{
		if (list->content)
			free(list->content);
		free(list);
	}
}
// clear nodes one by one after freeing it
void	clear_token(t_token **list)
{
	t_token *tmp;
	t_token *tmp2;

	if (!list)
		return;	
	tmp2 = *list;
	while (tmp2)
	{
		tmp = tmp2->next;
		clear(tmp2);
		tmp2 = tmp;
	}
	*list = NULL ;
}
int	join_str(t_token **token, t_token *tmp)
{
	if ((*token)->type == PIPE || (*token)->type == OPERATOR
		|| (*token)->type == SPACE)
		return (0);
	if (!tmp || tmp->type == PIPE || tmp->type == OPERATOR
		|| tmp->type == SPACE)
		return (0);
	else
	{
		tmp->content = ft_strjoin(tmp->content, (*token)->content);
		tmp->next = (*token)->next;
		// clear(*token);
		// clear_token(token);
		*token = tmp->next;
		return (1);
	}
}