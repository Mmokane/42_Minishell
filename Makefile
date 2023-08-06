# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 18:40:29 by mmokane           #+#    #+#              #
#    Updated: 2023/08/04 23:02:58 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

LDFLAGS += -lreadline -L/goinfre/$(USER)/homebrew/opt/readline/lib

INCLUDES += -I /goinfre/$(USER)/homebrew/opt/readline/include

SRCS = parser/tokens.c \
	   tools/env_utils.c  tools/tokens_utils.c \
	   minishell.c parser/env_dup.c expand/expand_utils.c \
	   expand/expand.c \
	   expand/expand_utils2.c parser/space_remover.c \
	   parser/parsing_utils.c parser/parsing.c \
	   tools/cmd_utils.c tools/redir_utils.c \
	   parser/error_check.c norm.c execution/builtins/ft_cd.c execution/builtins/ft_echo.c \
	   execution/builtins/ft_env.c execution/builtins/ft_exit.c execution/builtins/ft_export.c \
	   execution/builtins/ft_pwd.c execution/builtins/ft_unset.c execution/builtins/utils_builtins.c \
	   execution/builtins/exec_cmds.c execution/libft2/ft_lstnew.c execution/libft2/ft_lstadd_back.c \
	   execution/builtins/utils_export.c execution/libft2/ft_strjoin2.c execution/builtins/utils_export2.c \
	   execution/libft2/ft_strcpy.c execution/libft2/ft_strcat.c execution/libft2/ft_strstr.c \
	   execution/redirections/redirections.c execution/redirections/in_heredoc_redi.c \
	   execution/redirections/out_append_redi.c execution/redirections/heredoc.c \
	   execution/redirections/heredoc_utils.c execution/utils1.c execution/exec.c 
	   
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@make -C libft
		@cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) $(LDFLAGS) $(INCLUDES)
		@echo "\033[1;32mMY_SHELL! USE AT YOUR OWN RISK ;)\033[0m"
		@echo "\033[1;32m   -----DONE •̀ᴗ•̀-----\033[0m"	

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)
		
all : $(NAME)

clean : 
		@rm -rf	$(OBJS)
		@make clean -C libft

fclean :
		@rm -rf	$(NAME)
		@rm -rf	$(OBJS)
		@make fclean -C libft

re : fclean all 