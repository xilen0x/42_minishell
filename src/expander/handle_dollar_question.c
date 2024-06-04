/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_question.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:38:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/04 12:09:35 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar_question(t_xpdr *xpdr)
{
	xpdr->val = get_exit_status_val();//retorna un char* mallocado
	while (xpdr->val && xpdr->val[xpdr->k] != '\0')//mientras exista y no sea \0
	{
		xpdr->result[xpdr->j] = (xpdr->val[xpdr->k]);
		xpdr->j++;
		xpdr->k++;
	}
	str_free_and_null(&xpdr->val);//potser hauria de pasar-lo per referencia???
	xpdr->k = 0;
}
