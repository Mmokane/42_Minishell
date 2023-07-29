/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:44:59 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/29 02:51:21 by mmokane          ###   ########.fr       */
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
	heredoc,
	in,
	out,
	append,
};
enum {
	PIPE,
	DOUBLE,
	OPERATOR,
	SPACE,
	INSIDE_EXP,
	SINGLE,
	WORD,
};

typedef struct s_exp
{
	char	*str;
	char	*str2;
	char	*join;
	char	*last_str;
	char	*prev;
	int		j;
}		t_exp;
typedef struct s_token
{
	int				type;
	char			*content;
	int				expanded;
	struct s_token	*next;
}					t_token;

typedef struct s_redi
{
	int				type;
	char			*file;
	int				must_exp;
	struct s_redi	*next;
}					t_redi;

typedef struct s_env
{
	char			*keyword;
	char			*value;
	int				bolean;
	struct s_env	*next;
}					t_env;

typedef struct s_cmd
{
	char			**cmd;
	int				pipe;
	int				type;
	int				error;
	t_redi			*in;
	t_redi			*out;
	struct s_cmd	*next;
}					t_cmd;

void	arg_checker(int ac, t_env **env_v2, char **env);
void	*env_parsing(char **env, t_env **env_v2);
int		get_check_token(char *line, t_token **token);
int		token_type(char *content);
int		operator_type(char *content);
int		get_operator(char *line, t_token **token);
int		quotes_cheker(char *line, t_token **token, int c, int *flag);
int		get_word(char *line, t_token **token, int *flag);
t_env	*new_env_node(char *keyword, char *value, int bolean);
t_env	*last_env_node(t_env *list);
void	add_tolast_env(t_env **list, t_env *new_node);
int		get_index(char *str, int c);
t_token	*new_token_node(char *content);
t_token	*last_token_node(t_token *list);
void	add_tolast_node(t_token **list, t_token *new_token);
void	clear_token(t_token **list);
void	quotes_triming(t_token *token);
void	expand_type(t_token *token);
void	heredoc_expand(t_token *token);
void	expander(t_token **tokens, t_env *env, t_token *token);
void	expand_check(t_token *token, t_env *env);
int		acive_expand(int curr, int next);
void	variable_expander(t_env *env, char **content);
void	free_str(char *str1, char *str2, char *str3);
char	*variable_value(t_env *env, char *key);
int		counter(char *str);
void	space_remover(t_token **token, t_token *tok);
void	ft_remove(t_token *tmp, t_token **curr, t_token **token);
void	clear(t_token *list);
int		words_joiners(t_token **token, t_token *tmp);
void	cmd_start(t_cmd *cmd);
void	set_op(t_token *token, t_redi **redi, int type);
void	check_operator(t_token *token, t_cmd *cmd, t_token **tok);
void	args_set(t_token *token, t_cmd *cmd);
void	cmd_builder(t_cmd *cmd, t_token *token, int *i);
void	cmd_init(t_token **token, t_cmd **cmd);
void	cmd_parsing(t_token **token, t_cmd **cmd);
int		get_check_token(char *input, t_token **token);
t_cmd	*new_cmd_node(void);
t_cmd	*last_cmd_node(t_cmd *list);
void	add_tolast_cmdnode(t_cmd **list, t_cmd *new);
t_redi	*new_redir_node(char *out, int type);
t_redi	*last_redi_node(t_redi *list);
void	add_tolast_redi(t_redi **list, t_redi *new);
void	redi_clear(t_redi **list);
void	ft_free(char **str);
void	check_cmd(t_cmd *cmd);
int		true_redir(t_token *token);
void	cleaner(t_token *tmp, t_token **curr, t_token **token);
void	ft_free_tab2(char **arr);
void	clear_cmds(t_cmd **cmd);
// void	check_tokens(t_token *token);
void	redi_clear(t_redi **list);
int		error_exit_s(char *s, int fd);
int		syntax_check(t_token *token, t_token *tmp, int i);
int		syntax_er_find(t_token *token, t_token *tmp);
int		syntax_checker(t_token *token);
void	ac_check(int ac);
void	check_exit(char *input);
int		spaces_check(char *input);
void	check_check_spaces(char *input);
void	check_tokens(t_token *token);

#endif