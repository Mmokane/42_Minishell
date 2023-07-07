/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/07 01:06:39 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	check_tokens(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	printf("--------CHECK_TOKENS-----------\n");
	while (tmp)
	{
		printf("%s=", tmp->keyword);
		printf("%s\n", tmp->value);
		tmp = tmp->next;
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
		write(2, "minishell :", 12);
		write(2, "no such file or directory\n", 28);
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
			check_tokens(env_v2);	
			clear_token(&tokens);
		}
	}
}