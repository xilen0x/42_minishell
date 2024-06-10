/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_builder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:12:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 16:58:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	special_case(t_xpdr *xpdr, char c)
{
	xpdr->result[xpdr->j] = c;
	xpdr->j++;
	xpdr->i++;
}

void	handle_quote_builder(char c, t_xpdr *xpdr)
{
	if (c == '"' && xpdr->d_quote == CLOSED && xpdr->s_quote == CLOSED)
	{
		xpdr->d_quote = OPEN;
		xpdr->i++;
	}
	else if (c == '"' && xpdr->d_quote == OPEN)
	{
		xpdr->d_quote = CLOSED;
		xpdr->i++;
	}
	else if (c == '\'' && xpdr->s_quote == CLOSED && xpdr->d_quote == CLOSED)
	{
		xpdr->s_quote = OPEN;
		xpdr->i++;
	}
	else if (c == '\'' && xpdr->s_quote == OPEN)
	{
		xpdr->s_quote = CLOSED;
		xpdr->i++;
	}
	else
		special_case(xpdr, c);
}
