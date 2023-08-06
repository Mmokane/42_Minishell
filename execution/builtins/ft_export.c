/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:48:29 by taelkhal          #+#    #+#             */
/*   Updated: 2023/08/04 21:16:36 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	without_args(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (tmp->keyword)
		{
			printf("declare -x %s", tmp->keyword);
			if (ft_strcmp(tmp->value, "\0"))
			{
				if (tmp->value[0] != '\"' && tmp->value[ft_strlen(tmp->value)
						- 1] != '\"')
					printf("=\"%s\"", tmp->value);
				else
					printf("=%s", tmp->value);
			}
			printf("\n");
		}
		tmp = tmp->next;
	}
}

void	norm(t_env *env, char *key, char *value, int check)
{
	if (check == 1)
		append_value(env, key, value);
	else if (check == 2)
		replace_value(env, key, value);
}

void	with_args(t_env *env, char **args)
{
	int			check;
	char		*key;
	char		*value;
	int			i;

	i = 1;
	check = 0;
	while (args[i])
	{
		if (export_only_char(args[i]))
		{
			key = take_keyword(args[i], &check);
			value = take_value(args[i]);
			if (!keyword_is_available(&env, key))
			{
				if (charsrch(args[i]))
					ft_lstadd_back(&env, ft_lstnew(key, value));
				else
					ft_lstadd_back(&env, ft_lstnew(key, value));
			}
			else
				norm(env, key, value, check);
		}
		i++;
	}
}

void	ft_export(t_cmd *cmd_list, t_env *env)
{
	if (cmd_list->cmd[1] == NULL)
		without_args(&env);
	else
		with_args(env, cmd_list->cmd);
	return ;
}
