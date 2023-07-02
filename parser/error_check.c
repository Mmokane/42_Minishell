/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:17:31 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/02 16:28:49 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	format_erorr(t_token *token, t_token *tmp, int condition)
{
	if (condition)
	{
		if (tmp->type == PIPE && 
	}
}