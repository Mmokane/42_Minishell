/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:14:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/16 04:44:30 by mmokane          ###   ########.fr       */
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
	// if (content[0] && content[1] && !ft_strncmp(content, "<<", 2))
	// 	return (OPERATOR);
	// if (content[0] && content[1] && !ft_strncmp(content, ">>", 2))
	// 	return (OPERATOR);
	if (*content == '>' || *content == '<')
		return (OPERATOR);
	if (*content == ' ')
		return (SPACE);
	if (*content == '\'')
		return (SINGLE);
	else 
		return (WORD);
}

int operator_type(char *content)
{
	if (!ft_strncmp(content, ">>", 2) 
		|| !ft_strncmp(content, "<<", 2))
		return (2);
	if (*content == '|' || *content == '<'
		|| *content == '>')
		return (1);
	if (*content == 32 || *content == 9)
		return (3);
	return (0);
}
// we will check her for spaces at first then replace them all with one
// we will check if operator_type is size of one, then add it and return index of next one
// we check laso if operator_type has size of 2, addd it then return index + 2 to acces next one
int	get_operator(char *line, t_token **token)
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
		add_tolast_node(token, new_token_node(ft_substr(line + i, 0, 2)));
		return (i + 2);
	}
	return (i);		
}

// we keep checking for the quote character
// if we didnt find any , we return an error
// after finishing we check for the quote character
// and we crete token for the space before it then we return the after quote i
int	quotes_cheker(char *line, t_token **token, int c, int *flag)
{
	int i;

	i = 1;
	while (line[i] && line[i] != c)
		i++;
	if (line[i] != c)
	{
		write(2, "Error at quotes\n", 17);// give it 127 
		*flag = 0;
		return (0);
	}
	if (i)
		add_tolast_node(token, new_token_node(ft_substr(line, 0, i + 1)));
	return (i + 1);
}
// we check for quotes at the start, then we check for operators
// and we skip spaces , checking for operators aswell,
// we again check for i if its not 0, means there
// -were word before and i must add it
int	get_word(char *line, t_token **token, int *flag)
{
	int	i;

	i = 0;
	if (line[i] == 39 || line[i] == 34)
		return (quotes_cheker(line, token, *line, flag));
	if (operator_type(line + i))
		return (0);
	while (line[i] && !operator_type(line + i)
		&& line[i] != '\'' && line[i] != '\"')
		i++;
	if (i)
		add_tolast_node(token, new_token_node(ft_substr(line, 0, i)));
	return (i);
}

// void	check_tokens(t_token *token)
// {
// 	t_token	*tmp;

// 	tmp = token;
// 	printf("--------CHECK_TOKENS-----------\n");
// 	while (tmp)
// 	{
// 		printf("content = %s\n", tmp->content);
// 		printf("type    = %d\n", tmp->type);
// 		tmp = tmp->next;
// 	}
// 	printf("----------------------------\n");
// }
