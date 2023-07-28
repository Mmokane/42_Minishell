/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:17:31 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/27 19:42:16 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error_exit_s(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
	g_exit_status = 258;
	return (0);
}

int	syntax_check(t_token *token, t_token *tmp, int i)
{
	if (i)
	{
		if (tmp->type == OPERATOR && token->type == OPERATOR)
			return (
				error_exit_s("syntax error near unexpected token"
					, 2));
		if (tmp->type == OPERATOR && token->type == PIPE)
			return (
				error_exit_s("syntax error near unexpected token"
					, 2));
		if (tmp->type == PIPE && token->type == PIPE)
			return (
				error_exit_s("syntax error near unexpected token"
					, 2));
		if (tmp->type == PIPE && token->type == OPERATOR
			&& (!token->next || token->next->type == OPERATOR
				|| token->next->type == PIPE))
			return (
				error_exit_s("syntax error near unexpected token"
					, 2));
	}
	return (1);
}

int	syntax_er_find(t_token *token, t_token *tmp)
{
	if ((tmp->type == PIPE || tmp->type == OPERATOR)
		&& (token->type == PIPE || token->type == OPERATOR))
	{
		if (!syntax_check(token, tmp, 1))
			return (0);
	}
	return (1);
}

int	syntax_checker(t_token *token)
{
	t_token	*tmp;

	tmp = NULL;
	if (token && token->type == PIPE)
		return (error_exit_s("syntax error near unexpected token `|\'", 2));
	if (token && !token->next
		&& (token->type == OPERATOR))
		return (error_exit_s
			("syntax error near unexpected token `newline\'", 2));
	while (token)
	{
		if ((!ft_strcmp(token->content, "&&")
				|| !ft_strcmp(token->content, "&"))
			&& token->type == WORD)
			return (error_exit_s("syntax error, no bonus", 2));
		if (tmp && !syntax_er_find(token, tmp))
			return (0);
		tmp = token;
		token = token->next;
	}
	if (tmp && (tmp->type == OPERATOR || tmp->type == PIPE))
		return (error_exit_s
			("syntax error near unexpected token `newline\'", 2));
	return (1);
}
