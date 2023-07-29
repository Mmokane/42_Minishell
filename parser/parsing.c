/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:29:13 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/29 02:55:51 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	true_redir(t_token *token)
{
	int	len;

	len = ft_strlen(token->content) - 1;
	if (token->expanded)
	{
		if ((!*(token->content)) || (ft_strrchr(token->content, ' ')
				&& token->content[len] != ' '))
		{
			write(2, "ambiguous redirect\n", 20);
			g_exit_status = 1;
			return (1);
		}
	}
	return (0);
}

void	cmd_init(t_token **token, t_cmd **cmd)
{
	add_tolast_cmdnode(cmd, new_cmd_node());
	cmd_start(last_cmd_node(*cmd));
	check_operator(*token, *cmd, token);
	args_set(*token, last_cmd_node(*cmd));
}

void	cmd_parsing(t_token **token, t_cmd **cmd)
{
	t_token		*tok1;
	int			i;
	static int	pipe;
	static int a;
	tok1 = NULL;
	cmd_init(token, cmd);
	if (pipe && !last_cmd_node(*cmd)->in)
		last_cmd_node(*cmd)->pipe = pipe--;
	i = 0;
	tok1 = *token;
	while (tok1 && tok1->type != PIPE)
	{
		cmd_builder(last_cmd_node(*cmd), tok1, &i);
		tok1 = tok1->next;
	}
	if (!tok1)
		return ;
	*token = tok1->next;
	cmd_builder(last_cmd_node(*cmd), tok1, &i);
	clear(tok1);
	printf("--*--**--**-%s\n", tok1->content);
	printf("--*--**--**-%p\n", tok1->next);
	if (last_cmd_node(*cmd)->pipe)
		pipe++;
	system("leaks minishell");
	printf("a = %d\n", a);
	a++;
	printf("a = %d\n", a);
	return (cmd_parsing(token, cmd));
}

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
			write(2, "Token input error\n", 19);
			return (0);
		}
	}
	return (1);
}
