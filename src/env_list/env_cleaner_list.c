/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cleaner_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:33:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:33:09 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Deletes a 't_env' list and frees all its nodes */
void	cleaner_envlist(t_env **lst)
{
	t_env	*aux;

	aux = (*lst);
	while (aux)
	{
		free(aux->key);
		aux->key = NULL;
		free(aux->val);
		aux->val = NULL;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
