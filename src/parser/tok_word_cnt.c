/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_word_cnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:43:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:45:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*OJO, DE MOMENTO NO SE USA*/
/*-Counts the num of WORD on a list are found-*/
size_t	tok_word_cnt(t_tok *tokens)
{
	t_tok	*aux;
	size_t	cnt;

	aux = tokens;
	cnt = 0;
	while (aux && aux->type != PIPE)
	{
		if (aux->type == WORD)
			cnt++;
		aux = aux->next;
	}
	return (cnt);
}
