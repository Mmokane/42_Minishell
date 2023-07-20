/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:28:40 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/20 06:38:02 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*resulttab;
// 	size_t	size;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1)
// 		return (NULL);
// 	size = ft_strlen(s1) + ft_strlen(s2);
// 	resulttab = malloc(sizeof(char) * (size + 1));
// 	if (!resulttab)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[j])
// 		resulttab[i++] = s1[j++];
// 	j = 0;
// 	while (s2[j])
// 		resulttab[i++] = s2[j++];
// 	resulttab[i] = '\0';
// 	return (resulttab);
// }
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


