/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:28:50 by mmokane           #+#    #+#             */
/*   Updated: 2023/08/04 19:37:01 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_bool(const char *s, int c)
{
	char	c1;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	c1 = (char)c;
	while (*s != '\0' && *s != c1)
	{
		i++;
		s++;
	}
	if (*s == c1 && i < len)
		return (1);
	return (0);
}
