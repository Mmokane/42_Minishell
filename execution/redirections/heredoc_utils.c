/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:50:26 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 00:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	wait_signal(int pid, int fd)
{
	int	status;

	close(fd);
	waitpid(pid, &status, 0);
	g_exit_status = get_exit_status(status);
	return (0);
}

char	*name_generator(void)
{
	char	*file_fd;
	int		fd;
	int		random;
	char	*random_char;
	char	*str;

	fd = open("/dev/random", O_RDONLY);
	read(fd, &random, sizeof (rand));
	if (random < 0)
		random *= -1;
	random = random / 1000000;
	random_char = ft_itoa(random);
	str = ft_strjoin2("/tmp/", random_char);
	file_fd = ft_strdup(str);
	free (str);
	free(random_char);
	return (file_fd);
}

char	*delete_quotes(char *str)
{
	char	*without_quotes;
	int		i;
	int		j;

	i = 0;
	j = 0;
	without_quotes = malloc(sizeof(char ) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] == '\'' && str[i] == '\"')
			i++;
		if (str[i] != '\'' && str[i] != '\"')
		{
			without_quotes[j] = str[i];
			j++;
		}
		i++;
	}
	without_quotes[j] = '\0';
	return (without_quotes);
}

char	*ignore_spaces(char *str)
{
	char	*without_spaces;
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	without_spaces = ft_calloc(sizeof(char ), ((ft_strlen(str) - i) + 1));
	ft_strcpy(without_spaces, str + i);
	return (without_spaces);
}
