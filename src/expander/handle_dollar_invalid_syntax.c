/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_invalid_syntax.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:45:27 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/04 11:48:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar_invalid_syntax(char *str, t_xpdr *xpdr)
{
	if (str[xpdr->i] == '\'' || str[xpdr->i] == '"')//SI ES COMILLA.
	{
		xpdr->result[xpdr->j] = '$';//incluimos '$' en el result
		xpdr->j++;
		handle_quote_after_dollar(str[xpdr->i], xpdr);
	}
	else//SI NO ES COMILLA
	{
		xpdr->result[xpdr->j] = '$';//incluimos '$' en el resultado
		xpdr->j++;
		xpdr->result[xpdr->j] = str[xpdr->i];//incluimos el char actual
		xpdr->j++;
	}
}
