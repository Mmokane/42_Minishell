/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:32:22 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/08 02:55:53 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<fcntl.h>
#include<readline/readline.h>
 

void  lexer(char *input)
{
   int i = 0;
   int fd;
   enum Tokens;
   //input = readline(" ./minishell : ");
   fd = open("TOKENS.txt", O_CREAT | O_RDWR , 0777);
   while (input[i])
   {
      if (input[i] == PIPE)
      {
         write(fd, &input[i], strlen(input));
         // printf("%s\n", input[i]);
         write(fd, "          ", 10);
         // printf("%c\n", input[i]);
         // write(fd, input, strlen(input));
         // printf("%s\n", input);
         write(fd, "SPAC", 4);
         // printf("%s\n", input);
      }
      i++;
   }
   printf("content    lentgh: %d\n", fd);
}
int main()
{
   char *input;
   input = readline(" ./minishell : ");
   lexer(input);
}