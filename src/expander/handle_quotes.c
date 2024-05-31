/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:06:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/31 19:00:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Maneja y guarda el estado actual de las comillas: abiertas o cerradas*/
void	handle_quotes(char c, t_qts *quotes, t_len *len)
{
	if (c == '"' && quotes->d_quote == 0 && quotes->s_quote == 0)
		quotes->d_quote = 1;
	else if (c == '"' && quotes->d_quote == 1)
		quotes->d_quote = 0;
	else if (c == '\'' && quotes->s_quote == 0 && quotes->d_quote == 0)
		quotes->s_quote = 1;
	else if (c == '\'' && quotes->s_quote == 1)
		quotes->s_quote = 0;
	else if (c == '"' && quotes->s_quote == 1)//added para solucionar echo '"h"'
		len->len++;
}
