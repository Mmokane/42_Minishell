/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:29:13 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/30 14:02:38 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// here we will check for arguments, then we parse the environment.
// void	arg_checker(int ac, t_env **env_v2, char **env)
// {
// 	printf("sss");
// 	env_v2 = NULL;
	
// 	if (ac != 2)
// 	{
// 		write(2, "ERROR : Invalid argument", 25);
// 		exit (1);
// 	}
// 	env_parsing(env_v2, env);// we will take it somewhere else later .
// }



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
			write(2, "Token input error", 16);
			return (0);
		}
	}
	return (1);
}
