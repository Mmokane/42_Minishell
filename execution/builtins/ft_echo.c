/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:42:10 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/03 19:14:07 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	chech_n_is_option(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '-' && av[1] == 'n')
		i++;
	else
		return (1);
	while (av[i])
	{
		if (av[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	with_n(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] == '\0')
			i++;
		else
			break ;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (args[i])
			ft_putstr_fd(" ", 1);
	}
}

void	without_n(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (args[i])
			ft_putstr_fd(" ", 1);
	}
}

void	ft_echo(char **args)
{
	if (!args[1])
		printf("\n");
	else if (args[1][0] == '-' && args[1][1] == 'n')
		with_n(args);
	else
	{
		without_n(args);
		printf("\n");
	}
}
