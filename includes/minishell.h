/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:44:59 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/17 05:47:21 by mmokane          ###   ########.fr       */
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
void	arg_checker(int ac  );

enum {
	PIPE,
	DOUBLE,
	OPERATOR,
	SPACE,
	SINGLE_EXP,
	HYPHEN,
	SINGLE,
	WORD,
};
typedef struct s_token
{
	int				type;
	char			*content;
	int				expand;
	struct s_token *next;	
}		t_token;

typedef struct s_env
{
	char	*keyword;
	char	*value;
	int		bolean;
	struct	s_env *next;
}			t_env;

#endif