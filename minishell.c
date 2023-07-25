/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/25 05:26:48 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// void	check_tokens(t_token *token)
// {
// 	printf("--------CHECK_TOKENS-----------\n");
// 	while (token)
// 	{
// 		printf("content : |%s|\n", token->content);
// 		printf("type : %d\n", token->type);
// 		token = token->next;
// 	}
// 	printf("----------------------------\n");
// }
void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		printf(">>>>%s\n", str[i]);
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

int	ft_strchr_2(const char *str, int c)
{
	char			*ptr;
	int				i;
	unsigned char	ch;

	i = 0;
	ptr = (char *)str;
	ch = c;
	if (!str)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == ch)
			return (i);
		i++;
	}
	if (ptr[i] == ch)
		return (i);
	return (0);
}

void	check_cmd(t_cmd *cmd)
{
	char	**substr;
	// char	*temp;
	int		i;
	if (cmd->type == WORD && ft_strchr_2(cmd->cmd[0], ' '))
	{
		
		substr = ft_split(cmd->cmd[0], ' ');
		ft_free(cmd->cmd);
		i = 0;
		while(substr[i])
		// temp = cmd->cmd[0];
		// cmd->cmd[0] = ft_strdup(substr[0]);
		// free(temp);
		// if (substr[1])
		// {
		// 	temp = cmd->cmd[1];
		// 	cmd->cmd[1] = ft_strdup(substr[1]);
		// 	free(temp);
		// }
		// ft_free_tab2(substr);
		// printf(">>>> %s\n", substr[0]);
		printf(">>>> %s\n", cmd->cmd[0]);
		// printf(">>>> %s\n", substr[1]);
		printf(">>>> %s\n", cmd->cmd[1]);
	}
}

void	minishell(t_env **env, t_token **tokens, t_cmd **cmd)
{
	expander(tokens, *env, *tokens);
	space_remover(tokens, *tokens);
	cmd_parsing(tokens, cmd);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_token *tokens;
	t_env *env_v2;
	t_cmd *cmd;
	char *input;

	env_v2 = NULL;
	tokens = NULL;
	if (ac != 1)
	{
		write(2, "minishell : ", 13);
		write(2, "no such file or directory\n", 27);
		exit(1);
	}
	while (1)
	{
		input = readline("minishell:");
		if (!input)
			exit(EXIT_FAILURE);
		if (ft_strlen(input) != 0)
			add_history(input);
		// add exit status.
		arg_checker(ac, &env_v2, env);
		//check_tokens(env_v2);
		if(get_check_token(input, &tokens) == 1)
		{
			
			minishell(&env_v2, &tokens, &cmd);
			
			free(input);
		}
	}
}

