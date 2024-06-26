/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delone_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:28:23 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/02 16:28:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Removes a node from a 't-env' list
void	env_delone(t_env **env, char **node_to_del, void (*del)(void*))
{
	t_env	*current;
	t_env	*prev;

	current = *env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, *node_to_del) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env = current->next;
			del(current->key);
			del(current->val);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
