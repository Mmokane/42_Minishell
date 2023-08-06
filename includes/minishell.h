/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:44:59 by mmokane           #+#    #+#             */
/*   Updated: 2023/08/04 23:23:25 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <signal.h>
# include <limits.h>
# include <sys/wait.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# undef SPACE

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
	char			*here_file;
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

//----------execution----------------

//libft2

void	ft_lstadd_back(t_env **lst, t_env *new);
t_env	*ft_lstnew(char *keyword, char *value);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strjoin2(char *s1, char *s2);

//builtins
int		ft_cd(char **av, t_env *env);
void	ft_echo(char **args);
void	ft_env(t_env *env, char **args);
int		ft_exit(t_cmd *cmd_list);
void	ft_export(t_cmd *cmd_list, t_env *env);
int		ft_pwd(void);
void	ft_unset(t_cmd *cmd_list, t_env *env);
char	**env_to_array(t_env *env);
void	exec_builtins(t_cmd *cmd_list, t_env *env);
int		check_if_builtins(t_cmd *cmd);
void	exec_cmds(t_cmd *cmd_list, t_env **env);

//redirections_utils
char	*ignore_spaces(char *str);
char	*delete_quotes(char *str);
int		wait_signal(int pid, int fd);
char	*name_generator(void);

//redirections

void	input_redirection(t_cmd *cmd_list, int fd_in);
void	output_redirection(t_cmd *cmd_list, int fd_out);
void	ft_heredoc(t_cmd *cmd_list, t_env *env);
void	redirections(t_cmd *cmd_list);

//utils
void	close_fds(int *ends, int fd_in);
void	my_dup(int fd, int othe_fd);
void	dup_fds(int *ends, int fd_in);

//utils export
void	replace_value(t_env *env, char *key, char *value);
void	append_value(t_env *env, char *key, char *value);
char	*take_value(char *value);
char	*take_keyword(char *keyword, int *check);
char	charsrch(char *str);
int		export_only_char(char *keyword);
int		keyword_is_available(t_env **env, char *k);

void	exec(t_cmd *cmd_list, t_env *env);
void	*env_search(t_env **env_v2);
int		get_exit_status(int status);

#endif