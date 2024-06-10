/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_after_dollar.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:38:42 by joan              #+#    #+#             */
/*   Updated: 2024/06/03 11:03:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Manages quote just if it occurs next to a '$'*/
void	handle_quote_after_dollar(char c, t_xpdr *xpdr)
{
	if (c == '"' && xpdr->d_quote == CLOSED && xpdr->s_quote == CLOSED)
		xpdr->d_quote = OPEN;
	else if (c == '"' && xpdr->d_quote == OPEN)
		xpdr->d_quote = CLOSED;
	else if (c == '\'' && xpdr->s_quote == CLOSED && xpdr->d_quote == CLOSED)
		xpdr->s_quote = OPEN;
	else if (c == '\'' && xpdr->s_quote == OPEN)
		xpdr->s_quote = CLOSED;
}
