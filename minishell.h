/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:44:59 by mmokane           #+#    #+#             */
/*   Updated: 2023/06/08 02:01:13 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "parser/lexer.h"

typedef enum Tokens
{
	WORD = -1,
	SPAC = ' ',
	NEW_LINE = '\n',
	QUOTE = '\'',
	DQUOTE = '\"',
	BACK_SLASH = '\\',
	ENV = '$',
	PIPE = '|',
	LESS = '<',
	GREATER = '>',
	HERDOC,
	REDIR_OUT,
}	tokens ;

typedef struct S_Button
{
	int word;
	
}	t_button;
#endif