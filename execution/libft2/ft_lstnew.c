/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:13:33 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 21:13:33 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_lstnew(char *keyword, char *value)
{
	t_env	*list;

	list = (t_env *)malloc((sizeof(t_env)));
	if (list == NULL)
		return (NULL);
	list->keyword = keyword;
	list->value = value;
	list->next = NULL;
	return (list);
}
