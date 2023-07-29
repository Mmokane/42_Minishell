/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:28:40 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/29 02:52:47 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_free(char *p)
{
	free(p);
	return (NULL);
}

char	*ft_strjoin(char *old_str, char *current_str)
{
	size_t		arr[2];
	char		*new_str;

	if (!old_str)
		old_str = ft_strdup("\0");
	if (!current_str)
		return (old_str);
	if (!old_str || !current_str)
		return (ft_free(old_str));
	new_str = malloc(ft_strlen(old_str) + ft_strlen(current_str) + 1);
	if (!new_str)
		return (NULL);
	arr[0] = -1;
	if (old_str)
		while (old_str[++arr[0]] != '\0')
			new_str[arr[0]] = old_str[arr[0]];
	arr[1] = 0;
	while (current_str[arr[1]] != '\0')
		new_str[arr[0]++] = current_str[arr[1]++];
	new_str[ft_strlen(old_str) + ft_strlen(current_str)] = '\0';
	free(old_str);
	return (new_str);
}
