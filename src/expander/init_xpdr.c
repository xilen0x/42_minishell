/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpdr_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:36:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/03 11:16:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_xpdr(t_xpdr *xpdr)
{
	xpdr->i = 0;
	xpdr->j = 0;
	xpdr->k = 0;
	xpdr->len = 0;
	xpdr->s_quote = CLOSED;
	xpdr->d_quote = CLOSED;
	xpdr->key = NULL;
	xpdr->val = NULL;
	xpdr->result = NULL;
}
