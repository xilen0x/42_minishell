/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_operator_cnt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:46:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:47:00 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* OJO, DE MOMENTO NO SE USA*/
/*----Counts the num of redirection operators on a list---*/
size_t	tok_operator_cnt(t_tok *tokens)
{
	t_tok	*aux;
	size_t	cnt;

	aux = tokens;
	cnt = 0;
	while (aux && aux->type != PIPE)
	{
		if (aux->type == GREATER || aux->type == SMALLER \
		|| aux->type == D_GREATER || aux->type == D_SMALLER)
			cnt++;
		aux = aux->next;
	}
	return (cnt);
}
