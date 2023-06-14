/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:29:13 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/14 03:51:26 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	arg_checker(int ac, t_env *env_v2, char **env)
{
	env_v2 = NULL;
	
	if (ac != 1)
	{
		ft_putendl_fd("ERROR : Invalid argument", 2);
		exit (1);
	}
	env_parsing(env_v2, env);// we will take it somewhere else later .
}

void	*env_parsing(t_env *env_v2, char **env)
{
	
}

