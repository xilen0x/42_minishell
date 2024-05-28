/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:29:52 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:29:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

	if ((*lst) == NULL)
		return ;
	aux = (*lst);
	while (aux != NULL)
	{
		if (aux->commands != NULL)
			free_arr2d(aux->commands);
		if (aux->redir != NULL)
			redir_free(&aux->redir);
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
