/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_builder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:12:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/04 21:21:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*>>>>>>>>>>>OJO S'HA DER FER TOTA NOVA<<<<<<<<<<<<<<<<*/
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
	else//si ninguno actua significa que deberemos mostrar el caracter
	{
		xpdr->result[xpdr->j] = c;
		xpdr->j++;
		xpdr->i++;
	}
}
