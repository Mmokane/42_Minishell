/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:03:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/20 05:41:31 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// initialzing and creating new node to inset it to linked;
t_env	*new_env_node(char *keyword, char *value, int bolean)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	new_node->value = value;
	new_node->keyword = keyword;
	new_node->bolean = bolean;
	new_node->next = NULL;
	return (new_node);
}

// pointer to the head of the linked list, and return pointer to last node. 
t_env	*last_env_node(t_env *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// adds a new node to the bottom of linked list.. lstaddbackenv 
void	add_tolast_env(t_env **list, t_env *new_node)
{
	t_env	*last;

	if (! *list) // same mistake here XD
	{
		*list = new_node;
		return ;
	}
	last = last_env_node(*list);
	last->next = new_node;
}
