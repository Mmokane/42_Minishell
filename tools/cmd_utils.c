/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:30:07 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/24 03:36:20 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*new_cmd_node(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->err = 0;
	new->next = NULL;
	return (new);
}

t_cmd	*last_cmd_node(t_cmd *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_tolast_cmdnode(t_cmd **list, t_cmd *new)
{
	t_cmd	*last;

	last = *list;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

// void	clear_cmds(t_cmd **cmd)
// {
// 	t_cmd	*tmp1;
// 	t_cmd	*tmp2;

// 	if (!cmd || !*cmd)
// 		return ;
// 	tmp1 = *cmd;
// 	while (tmp1)
// 	{
// 		if (tmp1->in)
// 			ft_lstclear_2(&tmp1->in);
// 		if (tmp1->out)
// 			ft_lstclear_2(&tmp1->out);
// 		if (tmp1->cmd)
// 			ft_free_tab2(tmp1->cmd);
// 		tmp2 = tmp1->next;
// 		free(tmp1);
// 		tmp1 = tmp2;
// 	}
// }
