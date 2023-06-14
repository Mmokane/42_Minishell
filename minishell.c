/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:44:34 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/14 03:40:35 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"


// int ft(char *input)
// {		
// 	int i = 0;

// 	while (input[i])
// 			i++;
// 	return i;
// }
int main(int ac, char **av)
{
	char *input;
	(void)av;
	arg_checker(ac);
	input = readline("./minishell : ");
}