/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:22:32 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/30 15:29:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;

	c1 = (char)c;
	while (*s != '\0' && *s != c1)
		s++;
	if (*s == c1)
		return ((char *)s);
	else
		return (NULL);
}
