/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:26:41 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/29 02:51:49 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = NULL;
	if (size && count > SIZE_MAX / size)
		return (tab);
	tab = malloc(count * size);
	if (tab != NULL)
	{
		ft_bzero(tab, count * size);
		return (tab);
	}
	return (tab);
}
