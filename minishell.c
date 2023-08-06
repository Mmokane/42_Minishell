/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/08/04 23:05:04 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	sig_int_handler(int s)
{
	(void)s;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	set_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_int_handler);
}

void	minishell(t_env **env, t_token **tokens, t_cmd **cmd)
{
	(void)cmd;
	expander(tokens, *env, *tokens);
	space_remover(tokens, *tokens);
	if (syntax_checker(*tokens) == 1)
		cmd_parsing(tokens, cmd);
	else
		clear_token(tokens);
}

void	process_input(char *input, t_env **env_v2,
			t_token **tokens, t_cmd **cmd)
{
	if (*input != '\0')
	{
		check_check_spaces(input);
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		if (get_check_token(input, tokens) == 1)
		{
			minishell(env_v2, tokens, cmd);
			ft_heredoc(*cmd, *env_v2);
			exec(*cmd, *env_v2);
			clear_cmds(cmd);
		}
	}
	free(input);
}

int	main(int ac, char **av, char **env)
{
	t_token	*tokens;
	t_env	*env_v2;
	t_cmd	*cmd;
	char	*input;

	(void)av;
	env_v2 = NULL;
	tokens = NULL;
	cmd = NULL;
	ac_check(ac);
	arg_checker(ac, &env_v2, env);
	set_signals();
	while (1)
	{
		input = readline("minishell:");
		cmd = NULL;
		tokens = NULL;
		check_exit(input);
		process_input(input, &env_v2, &tokens, &cmd);
	}
}
