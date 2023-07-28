# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 18:40:29 by mmokane           #+#    #+#              #
#    Updated: 2023/07/28 00:11:38 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3 

SRCS = parser/tokens.c \
	   tools/env_utils.c  tools/tokens_utils.c \
	   minishell.c parser/env_dup.c expand/expand_utils.c \
	   expand/expand.c \
	   expand/expand_utils2.c parser/space_remover.c \
	   parser/parsing_utils.c parser/parsing.c \
	   tools/cmd_utils.c tools/redir_utils.c \
	   parser/error_check.c norm.c \
	   
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@make -C libft
		@cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) -lreadline 
		@echo "\033[1;32mMY_SHELL! USE AT YOUR OWN RISK ;)\033[0m"
		@echo "\033[1;32m   -----DONE •̀ᴗ•̀-----\033[0m"	

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		
all : $(NAME)

clean : 
		@rm -rf	$(OBJS)
		@make clean -C libft

fclean :
		@rm -rf	$(NAME)
		@rm -rf	$(OBJS)
		@make fclean -C libft

re : fclean all 