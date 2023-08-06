/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:07:34 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/03 19:14:34 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_env *env, char **args)
{
	t_env	*tmp;

	tmp = env;
	if (args[1])
		printf ("env: %s: No such file or directory\n", args[1]);
	else
	{
		while (tmp)
		{
			if (tmp->keyword && tmp->keyword)
			{
				ft_putstr_fd(tmp->keyword, 1);
				write (1, "=", 1);
				ft_putstr_fd(tmp->value, 1);
				write (1, "\n", 1);
			}
			tmp = tmp->next;
		}
	}
}
