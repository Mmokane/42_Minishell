/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/30 23:18:01 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	sig_int_handler(int s)
{
	(void)s;
	write(1, "\n", 1);
	g_exit_status = 1;
	rl_forced_update_display();
}

void	set_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_int_handler);
}
// void    get_input(t_cmd *command)
// {
//     t_cmd *cmd;
// 	t_redi *in;
// 	t_redi *out;
//     int     i;
//     int     x;
//     cmd = command;
// 	printf("----------TABLE-------------\n");
// 	i = 0;
// 	while (cmd)
//     {
//         x = 0;
//         while (cmd->cmd && cmd->cmd[x])
//         {
//             printf("[node:%d] cmd[%d] = %s\n", i, x, cmd->cmd[x]);
//             x++;
//         }
// 		printf("[node:%d] pipe   = %d\n", i,cmd->pipe);
// 		printf("[node:%d] er     = %d\n", i,cmd->error);
// 		printf("[node:%d] type     = %d\n", i,cmd->type);
//         if (cmd->in)
//         {
// 			in = cmd->in;
// 			while (in)
// 			{
// 				printf("-------------in-------------\n");
// 				printf("type = %d\n", in->type);
// 				printf("file = %s\n", in->file);
// 				printf("m_expd = %d\n", in->must_exp);
// 				in = in->next;
// 			}
//         }
//         if (cmd->out)
//         {
// 			out = cmd->out;
// 			while (out)
// 			{
// 			  printf("-------------out------------\n");
// 			  printf("type = %d\n", out->type);
// 			  printf("file = %s\n", out->file);
// 			  printf("m_expd = %d\n", out->must_exp);
// 			  out = out->next;
// 			}
//         }
//         printf("----------------------------\n");
// 		i++;
// 		cmd = cmd->next;
// 	}
// 	printf("\n");
// }

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
			get_input(*cmd);
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
