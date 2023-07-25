/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:29:13 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/24 03:37:09 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_parsing(t_token **token, t_cmd **cmd)
{
	
}


int	get_check_token(char *input, t_token **token)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (input[i])
	{
		i += get_operator(input + i, token);
		i += get_word(input + i, token, &flag);
		if (!flag)
		{
			clear_token(token);
			write(2, "Token input error\n", 19);
			return (0);
		}
	}
	return (1);
}

void	cmd_init(t_token **token, t_cmd **cmd)
{
	add_tolast_cmdnode(cmd, new_cmd_node());
	fill_cmd(last_cmd_node(*cmd));
}