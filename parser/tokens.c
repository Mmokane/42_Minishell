/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:14:54 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/10 03:59:32 by mmokane          ###   ########.fr       */
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
// ** 7yt mbghinach nbdlo l pointer li 3la struct, bghyt nchofo l val
