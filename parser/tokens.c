/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:14:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/13 03:39:06 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tokens *tokens_init(char *value , int type)
{
	t_tokens *tokens;
	
	tokens = malloc(sizeof(t_tokens));
	tokens->type = type;
	tokens->value = value;
	return (tokens);
}
t_tokens *tokens_lentgh(t_tokens **token)
{
	int i;

	i = 0;
	if (token)
	{
		while (token[i])
			i++;
	}
	return (token[i]);
}

void	tokens_clear(t_tokens **token)

{
		int i;
	i = 0;
	while (token[i])
	{
			free(token[i]->value);
		free(token[i]);
	}
	free(token);
}

t_tokens **expandin_token(t_tokens **old, t_tokens *token);
{
	t_tokens **new_tokens_array;
	int	i;
	int lenght;

	lentgh = tokens_length(old);
	new_tokens_array = (t_tokens **)malloc(sizeof(t_tokens *) * lentgh + 2);
	while (i < lenght)
	{
		new_tokens_array[i] = old[i];
		i++; 
	}
	free(old);
	new_tokens_array[i]	= token;
	i++;
	new_tokens_array[i] = NULL;
	return (new_tokens_array);
}