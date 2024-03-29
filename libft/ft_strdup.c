/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:27:01 by mmokane           #+#    #+#             */
/*   Updated: 2023/08/04 21:14:17 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dup = (char *)malloc(sizeof(char) * (size));
	if (dup != NULL)
		return (ft_memcpy(dup, s1, size));
	else
		return (NULL);
}
