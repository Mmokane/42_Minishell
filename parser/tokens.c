/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:14:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/19 10:55:10 by mmokane          ###   ########.fr       */
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
// we will check her for spaces at first then replace them all with one
// we will check if operator_type is size of one, then add it and return index of next one
// we check laso if operator_type has size of 2, addd it then return index + 2 to acces next one
int	get_operator_type(char *line, t_token **token)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == 32 || line[i] == 9))
		i++;
	if (i && *token)
		add_tolast_node(token, new_token_node(ft_strdup(" ")));
	if (operator_type(line + i) == 1)
	{
		add_tolast_node(token, new_token_node(ft_substr(line + i, 0, 1)));
		return (i + 1);
	}	
	if (operator_type(line + i) == 2)
	{
		add_tolast_node(token, new_token_node(ft_substr(line + i, 0, 2));
		return (i + 2);
	}
	return (i);		
}
