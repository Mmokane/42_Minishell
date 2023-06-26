/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:44:59 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/26 05:57:56 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

int	g_exit_status;



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

void	arg_checker(int ac, t_env **env_v2, char **env);
void	*env_parsing(t_env **env_v2, char **env);
int		get_check_token(char *line, t_token **token);
int		token_type(char *content);
int 	operator_type(char *content);
int		get_operator(char *line, t_token **token);
int		quotes_cheker(char *line, t_token **token, int c, int *flag);
int		get_word(char *line, t_token **token, int *flag);
t_env	*new_env_node(char *keyword, char *value, int bolean);
t_env	*last_env_node(t_env *list);
void	add_tolast_env(t_env **list, t_env *new_node);
int 	get_index(char *str, int c);
t_token *new_token_node(char * content);
t_token *last_token_node(t_token *list);
t_token *add_tolast_node(t_token **list, t_token *new_token);
void	clear_token(t_token **list);


#endif