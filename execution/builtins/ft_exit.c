/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:32:07 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 22:17:37 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit2(t_cmd *cmd_list)
{
	if (is_numeric(cmd_list->cmd[1]) == 0)
	{
		ft_putstr_fd("exit\n", 2);
		g_exit_status = ft_atoi(cmd_list->cmd[1]);
		exit(g_exit_status);
	}
	else
	{
		ft_putstr_fd("minishell : exit:", 2);
		ft_putstr_fd(cmd_list->cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_exit_status = 255;
		exit (g_exit_status);
	}
}

int	ft_exit(t_cmd *cmd_list)
{
	if (!cmd_list->cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		g_exit_status = 1;
		exit (g_exit_status);
	}
	else if (cmd_list->cmd[2])
	{
		if (is_numeric(cmd_list->cmd[2]) == 0)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			g_exit_status = 1;
			return (g_exit_status);
		}
		else
		{
			ft_putstr_fd("minishell : exit:", 2);
			ft_putstr_fd(cmd_list->cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			g_exit_status = 255;
			exit (g_exit_status);
		}
	}
	ft_exit2(cmd_list);
	return (0);
}
