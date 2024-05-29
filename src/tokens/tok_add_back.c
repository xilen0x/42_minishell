/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:59:06 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 11:59:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----Adds a node to the end of a list t_tok----*/
void	tok_add_back(t_tok **lst, t_tok *new)
{
	t_tok	*aux;

	if (*lst)
	{
		aux = tok_last(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
