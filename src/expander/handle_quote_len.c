/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:11:47 by joan              #+#    #+#             */
/*   Updated: 2024/06/07 16:24:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*-----------Manages quotes---------*/
void	handle_quote_len(char c, t_xpdr *xpdr)
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
	{
		xpdr->i++;
		xpdr->len++;
	}
}
