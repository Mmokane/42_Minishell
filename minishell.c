/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/27 04:29:57 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	minishell(t_env **env, t_token **tokens, t_cmd **cmd)
{
	expander(tokens, *env, *tokens);
	space_remover(tokens, *tokens);
	if (syntax_checker(*tokens) == 1)
	{
		cmd_parsing(tokens, cmd);
	}
	else
		clear_token(tokens);
}

int	main(int ac, char **env)
{
	t_token	*tokens;
	t_env	*env_v2;
	t_cmd	*cmd;
	char	*input;

	env_v2 = NULL;
	tokens = NULL;
	ac_check(ac);
	arg_checker(ac, &env_v2, env);
	// set_signals
	while (1)
	{
		input = readline("minishell:");
		check_check_spaces(input);
		check_exit(input);
		if (!input)
			exit(EXIT_FAILURE);
		if (ft_strlen(input) != 0)
			add_history(input);
		if (get_check_token(input, &tokens) == 1)
			minishell(&env_v2, &tokens, &cmd);
	}
	free(input);
}
