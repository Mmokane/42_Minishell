/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:14:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/17 07:29:05 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_type(char *content)
{
	if (*content == '|')
		return (PIPE);
	if (*content == '\"')
		return (DOUBLE);
	if (!ft_strncmp(content, ">>", 2) 
		|| !ft_strncmp(content, "<<", 2))
		return (OPERATOR);
	if (*content == '>' || *content == '<')
		return (OPERATOR);
	if (*content == ' ')
		return (SPACE);
	if (*content == '~')
		return (HYPHEN);
	else 
		return (WORD);
}

int operator_type(char *content)
{
	if (*content == '|' || *content == '<'
		|| *content == '>')
		return (1);
	if (!ft_strncmp(content, ">>", 2) 
		|| !ft_strncmp(content, "<<", 2))
		return (2);
	if (*content == 32 || *content == 9)
		return (3);
	return (0);
}
int	get_operator_type(char *line, t_token *token)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == 32 || line[i] == 9))
		i++;
	
		
}

int	take_operator(char *line, t_token **token)
{
	int	i;

	i = 0;
	while (line[i] && ((line[i] >= 9 && line[i] <= 12) || line[i] == 32))
		i++;
	if (i && *token)
		add_tolast_node(token, new_token_node(ft_strdup("")));
		
}

> guys
012345