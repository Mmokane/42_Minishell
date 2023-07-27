/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:06:55 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/27 04:24:54 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ac_check(int ac)
{
	g_exit_status = 0;
	if (ac != 1)
	{
		write(2, "minishell : ", 13);
		write(2, "no such file or directory\n", 27);
		exit(1);
	}
}

void	check_exit(char *input)
{
	if (!input)
	{
		ft_putstr_fd("exit\n", 2);
		exit(g_exit_status);
	}
}
int	spaces_check(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((input[i] != ' ' || input[i] != '\n' || input[i] != '\t'))
			return (0);
		i++;
	}
	return (1);
}

void	check_check_spaces(char *input)
{
	if (spaces_check(input))
	{
		free(input);
	}
}
