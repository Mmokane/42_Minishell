/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 04:07:08 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/25 05:32:00 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    new_redir_node(char *out, int *type)
{
    t_redi *tmp;

    tmp = malloc(sizeof(t_redi));
    ptr->file = out;
    ptr->type = type;
    ptr->must_exp = 0;
    ptr->next = NULL;
    return (ptr);
}

void    last_redi_node(t_redi *list)
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

    last = *lst;
    if (!(*list))
    {
        *lst = new;
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

    tmp = *list;//might cause a problem 
    if (!tmp)
        return ;
    while (tmp)
    {
        tmp2 = tmp->next;
        free(tmp->file);
        free(tmp);
        tmp = tmp2;
    }
    *tmp = NULL;
}