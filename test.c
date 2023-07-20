/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:25:23 by mmokane           #+#    #+#             */
/*   Updated: 2023/07/20 02:05:16 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	must_expand(int next)
{
	if (!ft_isalnum(next) && next != '_')
		return (1);
	return (0);
}
int	count(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) || str[i] == '?')
		return (1);
	while (str[i] && (!(!ft_isalnum(str[i]) && str[i] != '_')))
		i++;
	// // if (curr == '$' && next == '?')
	// // 	return (1);
	// if (curr == '$' && (!(!ft_isalnum(next) && next != '_')
	// 	 || next == '?'))
	// 	return (1);
	// return (0);
	return (i);
}
int main()
{
	char *str = "f?";
	printf("%d\n", count(str));
}

// int	must_expand(int next)
// {
// 	if (!ft_isalnum(next) && next != '_')
// 		return (1);
// 	return (0);
// }
