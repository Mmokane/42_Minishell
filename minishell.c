/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/26 05:53:49 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"



int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	t_token *token;
	
	char *input;

	input = readline("MINISHELL :");
	get_check_token(input, &token);
	while (token)
	{
		printf("%d\n", token->type);	
		printf("%s\n", token->content);	
	}
}