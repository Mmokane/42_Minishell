# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 18:40:29 by mmokane           #+#    #+#              #
#    Updated: 2023/06/09 22:08:40 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc 

CFLAGS = -Wall -Werror -Wextra 

SRCS = minishell.c test.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@cc $(CFLAGS) -lreadline $(OBJS)  -o  $(NAME)
		@echo "\033[1;32m ----DONE •̀ᴗ•̀----\033[0m"

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		
all : $(NAME)

clean : 
		@rm -rf	$(OBJS)

fclean :
		@rm -rf	$(NAME)
		@rm -rf	$(OBJS)

re : fclean all 