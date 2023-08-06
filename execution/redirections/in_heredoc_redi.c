/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_heredoc_redi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:44:33 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 00:44:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	heredoc_file(t_redi *redr)
{
	int	fd;

	fd = open(redr->here_file, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}

int	get_input_redirection_fd(t_redi *redr, int fd_in)
{
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	if (redr->type == in)
	{
		fd_in = open(redr->file, O_RDONLY, 0644);
		return (fd_in);
	}
	else if (redr->type == heredoc)
	{
		fd_in = heredoc_file(redr);
		return (fd_in);
	}
	return (fd_in);
}

void	dup_redi_in(t_cmd *cmd_list, int fd_in)
{
	t_redi	*red_in;
	int		check;

	check = 0;
	red_in = cmd_list->in;
	while (red_in)
	{
		if (red_in->type == in || red_in->type == heredoc)
			check = 1;
		red_in = red_in->next;
	}
	if (check)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
}

void	input_redirection(t_cmd *cmd_list, int fd_in)
{
	t_redi	*red_in;

	if (cmd_list->in)
	{
		red_in = cmd_list->in;
		while (red_in)
		{
			if (red_in->type == in || red_in->type == heredoc)
				fd_in = get_input_redirection_fd(red_in, fd_in);
			if (fd_in < 0)
			{
				perror("open");
				g_exit_status = 1;
				exit(g_exit_status);
			}
			red_in = red_in->next;
		}
		dup_redi_in(cmd_list, fd_in);
	}
}
