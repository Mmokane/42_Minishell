/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:29:13 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/23 04:08:48 by mmokane          ###   ########.fr       */
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

int	get_check_token(char *line, t_token **token)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (line[i])
	{
		i += get_operator(line + i, token);
		i += get_word(line + i, token, &flag);
		if (!flag)
		{
			ft_lstclear_t(token);
			write(2, "Token line error", 16);
			return (0);
		}
	}
	return (1);
}
