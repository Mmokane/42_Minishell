//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/28 14:20:19 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	check_tokens(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	printf("--------CHECK_TOKENS-----------\n");
	while (tmp)
	{
		printf("content = %s\n", tmp->content);
		printf("type    = %d\n", tmp->type);
		tmp = tmp->next;
	}
	printf("----------------------------\n");
}
void    get_input(t_cmd *command)
{

    t_cmd *cmd;
	t_redi *in;
	t_redi *out;

    int     i;
    int     x;
    cmd = command;
	printf("----------TABLE-------------\n");
	i = 0;
	while (cmd)
    {
        x = 0;
        while (cmd->cmd && cmd->cmd[x])
        {
            printf("[node:%d] cmd[%d] = %s\n", i, x, cmd->cmd[x]);
            x++;
        }
		printf("[node:%d] pipe   = %d\n", i,cmd->pipe);
		printf("[node:%d] er     = %d\n", i,cmd->error);
		printf("[node:%d] type     = %d\n", i,cmd->type);
        if (cmd->in)
        {
			in = cmd->in;
			while (in)
			{
				printf("-------------in-------------\n");
				printf("type = %d\n", in->type);
				printf("file = %s\n", in->file);
				printf("m_expd = %d\n", in->must_exp);
				in = in->next;
			}
        }
        if (cmd->out)
        {
			out = cmd->out;
			while (out)
			{
			  printf("-------------out------------\n");
			  printf("type = %d\n", out->type);
			  printf("file = %s\n", out->file);
			  printf("m_expd = %d\n", out->must_exp);
			  out = out->next;
			}
        }
        printf("----------------------------\n");
		i++;
		cmd = cmd->next;
	}
	printf("\n");
}
void	minishell(t_env **env, t_token **tokens, t_cmd **cmd)
{
	(void)cmd;
	expander(tokens, *env, *tokens);
	space_remover(tokens, *tokens);
	if (syntax_checker(*tokens) == 1)
	{
		cmd_parsing(tokens, cmd);
		clear_token(tokens);
	}
	else
		clear_token(tokens);
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	t_token	*tokens;
	t_env	*env_v2;
	t_cmd	*cmd;
	char	*input;

	env_v2 = NULL;
	tokens = NULL;
	cmd = NULL;
	ac_check(ac);
	arg_checker(ac, &env_v2, env);
	// set_signals
	while (1)
	{
		input = readline("minishell:");
		cmd = NULL;
		tokens = NULL;
		check_exit(input);
		if (*input != '\0')
		{
			check_check_spaces(input);
			if (!input)
				exit(EXIT_FAILURE);
			add_history(input);
			if (get_check_token(input, &tokens) == 1)
			{
				check_tokens(tokens);
				minishell(&env_v2, &tokens, &cmd);
				get_input(cmd);
				check_tokens(tokens);
				clear_token(&tokens);
				clear_cmds(&cmd);
			}
			clear_token(&tokens);
			free(input);
			//system("leaks minishell");
		}
		input = NULL;
	}
}
