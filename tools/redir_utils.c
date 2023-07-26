/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 04:07:08 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/25 23:36:32 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_redi    *new_redir_node(char *out, int type)
{
    t_redi *tmp;

    tmp = malloc(sizeof(t_redi));
    tmp->file = out;
    tmp->type = type;
    tmp->must_exp = 0;
    tmp->next = NULL;
    return (tmp);
}

t_redi    *last_redi_node(t_redi *list)
{
    if (!list)
        return (NULL);
    while(list->next)
        list = list->next;
    return (list);
}    

void    add_tolast_redi(t_redi **list, t_redi *new)
{
    t_redi *last;

    last = *list;
    if (!(*list))
    {
        *list = new;
        return ;
    }
    while (last->next)
        last = last->next;
    last->next = new;
}

void    redi_clear(t_redi **list)
{
    t_redi  *tmp;
    t_redi  *tmp2;

    if (!list)
        return ;
    tmp = *list;//might cause a problem 
    while (tmp)
    {
        tmp2 = tmp->next;
        free(tmp->file);
        free(tmp);
        tmp = tmp2;
    }
    *list = NULL;
}

// void	ft_lstclear_2(t_redi **lst)
// {
// 	t_redi	*ptr;
// 	t_redi	*tmp;

// 	if (!lst)
// 		return ;
// 	ptr = *lst;
// 	while (ptr)
// 	{
// 		tmp = ptr->next;
// 		free(ptr->file);
// 		free(ptr);
// 		ptr = tmp;
// 	}
// 	*lst = NULL;
// }