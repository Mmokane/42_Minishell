/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:28:02 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/25 07:04:14 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    cmd_start(t_cmd *cmd)
{
    cmd->cmd = NULL;
    cmd->in = NULL;
    cmd->out = NULL;
    cmd->pipe = 0;
}
// might have a pblm here
void    set_op(t_token *token, t_redi **red, int type)
{
    if (token)
    	add_tolast_redi(red, 
            new_redir_node(ft_strdup(token->content), type));
    if (token && type == heredoc && token->type == INSIDE_EXP)
        last_redi_node(*red)->must_exp = 1;
}

void    is_it_op(t_token *token, t_cmd *cmd)
{
    if (token->next)
    {
        if (true_redir(token->next))
        {
            cmd->error = 1;
            return ;
        }
    }
        if (!ft_strcmp(token->content, ">>"))
            set_op(token->next, &cmd->out, append);
        else if (*(token->content) == '>')
            set_op(token->next, &cmd->out, out);
        else if (!ft_strcmp(token->content, "<<"))
            set_op(token->next, &cmd->out, heredoc);
       else if (*(token->content) == '<')
            set_op(token->next, &cmd->out, in);
}
void    check_operator(t_token *token, t_cmd *cmd,t_token **tok)
{
    t_token *tmp;
    t_token *tmp2;

    tmp = NULL;
    while(token && token->type != PIPE)
    {
        is_it_op(token, last_cmd_node(cmd));
        if(token && token->next)
        {
            tmp2 = token->next->next;
            cleaner(token, &token->next, tok);
            cleaner(tmp, &token, tok);
            token = tmp2;
        }
        else
        {
            tmp = token;
            token = token->next;
        }
    }
}

void    args_set(t_token *token, t_cmd *cmd)
{
    int i;

    i = 0;
    while(token && token->type != PIPE)
    {
        if (token->type == WORD || token->type == DOUBLE
			|| token->type == SINGLE)
			i++;
		token = token->next;
    }
    // prtoext the i ig
    cmd->cmd = malloc(i * sizeof(char *));
    if (!cmd->cmd)
        return ;
    cmd->cmd[--i] = NULL;
}

void	cmd_builder(t_cmd *cmd, t_token *token, int *i)
{
	if (!token || token->type == SPACE)
		return ;
	if (token && !token->content)
		return ;
	if ((token->type == WORD || token->type == SINGLE
			|| token->type == DOUBLE) && cmd->cmd)
	{
		cmd->cmd[(*i)++] = ft_strdup(token->content);
		cmd->type = token->type;
	}
	else if (*(token->content) == '|')
	{
		if (token->next && token->next->content)
			cmd->pipe = 1;
	}
}


