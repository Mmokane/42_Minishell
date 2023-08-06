/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:31:00 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 01:31:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_fds(int *ends, int fd_in)
{
	if (ends[1] > 2)
		close(ends[1]);
	if (fd_in != STDIN_FILENO)
		close(fd_in);
}

void	my_dup(int fd, int othe_fd)
{
	dup2(fd, othe_fd);
	close(fd);
}

void	dup_fds(int *ends, int fd_in)
{
	if (fd_in != STDIN_FILENO)
		my_dup(fd_in, STDIN_FILENO);
	my_dup(ends[1], STDOUT_FILENO);
	if (ends[0] > 2)
		close(ends[0]);
}

int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (0);
}
