/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:25:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:25:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----Libera y limpia una lista t_redir----*/
void	redir_free(t_redir **lst)
{
	t_redir	*aux;

	aux = (*lst);
	while (aux)
	{
		if (aux->fname != NULL)
		{
			free(aux->fname);
			aux->fname = NULL;
		}
		if (aux->redir_type != 0)
			aux->redir_type = 0;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
