/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:44:59 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/15 01:32:03 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

int	g_exit_status;

int ft(char *input);
void	arg_checker(int ac, t_env *env, char **env);

typedef struct s_env
{
	char	*keyword;
	char	*value;
	int		confirmation;
	struct	s_env *next;
}			t_env;

#endif