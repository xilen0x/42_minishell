/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:06:50 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 11:43:33 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*--Frees and points to NULL a 't_tok' list--*/

void	tok_free(t_tok **lst)
{
	t_tok	*aux;

	aux = (*lst);
	if (lst == NULL || (*lst) == NULL)
		return ;
	while (aux != NULL)
	{
		if (aux->str != NULL)
		{
			free(aux->str);
			aux->str = NULL;
		}
		aux->type = NULL_TYPE;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
