/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:29:13 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/16 05:53:45 by mmokane          ###   ########.fr       */
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

void	*env_parsing(t_env **env_v2, char **env)
{
	int i;

	while(*env)
	{
		i = get_index(*env, '=');
		add_tolast_env(env_v2,
			new_env_node(ft_substr(*env, 0, i),
				ft_substr(*env, i + 1, ft_strlen(*env) - i), 1));
		env++;	
	}
	return (env_v2);
}

// HOME=/users/...
// 0123456789
// = index is 4;

// keyowrd is from 0 to 4 : HOME;
// value is from i + 1 to env -i (4), 1

