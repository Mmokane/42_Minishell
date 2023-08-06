/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:53:27 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 00:29:21 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_if_valid_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!((arg[i] >= 'a' && arg[i] <= 'z')
				|| (arg[i] >= 'A' && arg[i] <= 'Z') || arg[i] == '_'))
		{
			ft_putstr_fd("unset: not a valid identifier\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	remove_env_node(t_env *env, char *key)
{
	t_env	*current;
	t_env	*prev;
	t_env	*tmp;

	tmp = env;
	if (tmp && (ft_strcmp(tmp->keyword, key)) == 0)
	{
		current = tmp;
		tmp = tmp->next;
		free(current->keyword);
		free(current->value);
		free(current);
		return ;
	}
	while (tmp && (ft_strcmp(tmp->keyword, key)))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free(tmp->keyword);
	free(tmp->value);
	free(tmp);
}

void	ft_unset(t_cmd *cmd_list, t_env *env)
{
	int	i;

	if (!cmd_list->cmd[1])
		return ;
	if (!check_if_valid_arg(cmd_list->cmd[1]))
		return ;
	i = 1;
	while (cmd_list->cmd[i])
	{
		if (check_if_valid_arg(cmd_list->cmd[i]) == 1)
			remove_env_node(env, cmd_list->cmd[i]);
		i++;
	}
}
