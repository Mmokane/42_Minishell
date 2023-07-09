/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:50:48 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/09 02:47:28 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
	return (0);
}
int main()
{
	char str[] = "hey";
	ft_putendl_fd(str, 2);
}