/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:31:38 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:31:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Returns a malloced 't_env' new node initialized with the arguments
t_env	*lstnew(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)p_malloc(sizeof(t_env));
	new_node->key = ft_strdup(key);
	new_node->val = ft_strdup(value);
	new_node->next = NULL;
	return (new_node);
}
