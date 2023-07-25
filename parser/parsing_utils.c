// add header xd;


#include "../includes/minishel.h"

void    fill_cmd(t_cmd *cmd)
{
    cmd->cmd = NULL;
    cmd->in - NULL;
    cmd->out = NULL;
    cmd->pipe = 0;
}

void    set_op(t_token **token, t_redir **redi, int type)// might get a prblm here
{
    if (token)
    	add_tolast_redi(redi, 
            new_redir_node(ft_strdup(token->content), type);
    if (token && type == heredoc && token->type == INSIDE_EXP)
        last_redi_node(*redi)->must_exp = 1;
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
        else if (!ft_strcmp(token->next, '>'))
            set_op(token->next, &cmd->out, out);
        else if (!ft_strcmp(token->next, "<<"))
            set_op(token->next, &cmd->out, heredoc);
        else if (!ft_strcmp(token->next, '<'))
            set_op(token->next, &cmd->out, in)
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