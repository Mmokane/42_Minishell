/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_append_redi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:13:47 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 21:13:47 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_output_redirection_fd(t_redi *redr, int fd_out)
{
	if (fd_out != STDOUT_FILENO)
		close(fd_out);
	if (redr->type == out)
	{
		fd_out = open(redr->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		return (fd_out);
	}
	else if (redr->type == append)
	{
		fd_out = open(redr->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		return (fd_out);
	}
	return (fd_out);
}

void	dup_redi_out(t_cmd *cmd_list, int output)
{
	t_redi	*red_out;
	int		check;

	check = 0;
	red_out = cmd_list->out;
	while (red_out)
	{
		if (red_out->type == out || red_out->type == append)
			check = 1;
		red_out = red_out->next;
	}
	if (check)
	{
		dup2(output, STDOUT_FILENO);
		close(output);
	}
}

void	output_redirection(t_cmd *cmd_list, int fd_out)
{
	t_redi	*red_out;

	red_out = cmd_list->out;
	if (cmd_list->out)
	{
		while (red_out)
		{
			if (red_out->type == out || red_out->type == append)
				fd_out = get_output_redirection_fd(red_out, fd_out);
			if (fd_out < 0)
			{
				perror("open");
				g_exit_status = 1;
				exit(g_exit_status);
			}
			red_out = red_out->next;
		}
		dup_redi_out(cmd_list, fd_out);
	}
}
