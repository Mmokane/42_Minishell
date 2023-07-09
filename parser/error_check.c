/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:17:31 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/09 03:11:45 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int syntax_checker(t_token *token)
{
	t_token *tmp;

	tmp = NULL;
	if (token)
	{
		if (token->type == PIPE)
			ft_putendl_fd("syntax error near unexpected token `|'", 2);
		if (!token->next && token->next == OPERATOR)
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
	}
}