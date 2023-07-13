/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/13 06:19:33 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	check_tokens(t_token *token)
{
	printf("--------CHECK_TOKENS-----------\n");
	while (token)
	{
		printf("content : |%s|\n", token->content);
		printf("type : %d\n", token->type);
		token = token->next;
	}
	printf("----------------------------\n");
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_token *tokens;
	t_env *env_v2;
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
			// expand()
			check_tokens(tokens);	
			clear_token(&tokens);
		}
	}
}

// int	check_syntax(t_token *token)
// {
// 	t_token	*tmp;

// 	tmp = NULL;
// 	if (token && token->type == PIPE)
// 		return (ft_putendl_fd_2("syntax error near unexpected token", "|", 2));
// 	if (token && !token->next
// 		&& (token->type == OPERATOR || token->type == PIPE))
// 		return (ft_putendl_fd_2("syntax error near unexpected token",
// 				"newline", 2));
// 	while (token)
// 	{
// 		if (token->check == 1)
// 			return (ft_putendl_fd_2("ambiguous redirect", NULL, 2));
// 		if ((!ft_strcmp(token->content, "&&")
// 				|| !ft_strcmp(token->content, "&"))
// 			&& token->type == WORD)
// 			return (ft_putendl_fd_2("syntax error asat", "haha", 2));
// 		if (tmp && !find_error(token, tmp))
// 			return (0);
// 		tmp = token;
// 		token = token->next;
// 	}
// 	if (tmp && (tmp->type == OPERATOR || tmp->type == PIPE))
// 		return (ft_putendl_fd_2("syntax error near unexpected token",
// 				"newline", 2));
// 	return (1);
// }

// int	ft_putendl_fd_2(char *s, char *str, int fd)
// {
// 	if (!s)
// 	{
// 		write (fd, "\n", 1);
// 		return (0);
// 	}
// 	if (str && *str == '/')
// 		str++;
// 	while (*s)
// 	{
// 		write (fd, s, 1);
// 		s++;
// 	}
// 	if (str)
// 	{
// 		write(fd, "`", 1);
// 		while (*str)
// 		{
// 			write (fd, str, 1);
// 			str++;
// 		}
// 		write(fd, "\'", 1);
// 	}
// 	write (fd, "\n", 1);
// 	g_exec.g_exit_status = 258;
// 	return (0);
// }
