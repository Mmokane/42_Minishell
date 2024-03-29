/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 04:07:08 by mmokane           #+#    #+#             */
/*   Updated: 2023/08/04 01:51:00 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_redi	*new_redir_node(char *out, int type)
{
	t_redi	*tmp;

	tmp = (t_redi *)malloc(sizeof(t_redi));
	tmp->file = out;
	tmp->type = type;
	tmp->here_file = NULL;
	tmp->must_exp = 0;
	tmp->next = NULL;
	return (tmp);
}

t_redi	*last_redi_node(t_redi *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_tolast_redi(t_redi **list, t_redi *new)
{
	t_redi	*last;

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

void	redi_clear(t_redi **list)
{
	t_redi	*tmp;
	t_redi	*tmp2;

	if (!list)
		return ;
	tmp = *list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free (tmp->file);
		if (tmp->here_file)
		{
			unlink(tmp->here_file);
			free(tmp->here_file);
		}
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
}
