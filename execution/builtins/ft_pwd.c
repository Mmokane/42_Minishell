/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:49:02 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 22:44:59 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 1000);
	if (!pwd)
	{
		perror("");
		return (1);
	}
	ft_putstr_fd(pwd, 1);
	write (1, "\n", 1);
	free(pwd);
	return (g_exit_status);
}
