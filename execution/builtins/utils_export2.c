/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:13:25 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 21:13:25 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_export(char *keyword)
{
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd(keyword, 2);
	ft_putstr_fd(" : not a valid identifie\n", 2);
}

int	export_only_char(char *keyword)
{
	int		i;
	int		check;

	i = 0;
	check = 1;
	if (!keyword)
		exit (1);
	while (keyword[i] != '\0')
	{
		if ((keyword[i] >= 'A' && keyword[i] <= 'Z')
			&& (keyword[i] >= 'a' && keyword[i] <= 'z'))
		{
			check = 0;
			break ;
		}
		i++;
	}
	if (check == 0 || (keyword[0] >= '0' && keyword[0] <= '9'))
	{
		error_export(keyword);
		return (0);
	}
	return (1);
}

int	keyword_is_available(t_env **env, char *k)
{
	t_env	*tmp;

	tmp = (*env);
	while (tmp)
	{
		if (!ft_strcmp(tmp->keyword, k))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
