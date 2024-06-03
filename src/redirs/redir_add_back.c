/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:25:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:25:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----Adds a node to the end of a list t_redir----*/
void	redir_add_back(t_redir **lst, t_redir *new)
{
	t_redir	*aux;

	if (*lst)
	{
		aux = redir_last(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
