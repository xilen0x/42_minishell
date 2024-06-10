/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpdr_except_result.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:16:24 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/03 11:19:28 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_xpdr_except_result(t_xpdr *xpdr)
{
	xpdr->i = 0;
	xpdr->j = 0;
	xpdr->k = 0;
	xpdr->len = 0;
	xpdr->s_quote = CLOSED;
	xpdr->d_quote = CLOSED;
	xpdr->key = NULL;
	xpdr->val = NULL;
}
