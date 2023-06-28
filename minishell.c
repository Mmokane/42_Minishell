/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/28 00:32:29 by mmokane          ###   ########.fr       */
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

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_token *tokens;
	t_env *env_v2;
	char *input;

	env_v2 = NULL;
	tokens = NULL;
	printf("Zping!\n");
	arg_checker(ac, av, &env_v2, env);
	while (1)
	{
		input = readline("minishell:");
		if (!input)
			exit(EXIT_FAILURE);
		if (ft_strlen(input) != 0)
			add_history(input);
		
	}
}