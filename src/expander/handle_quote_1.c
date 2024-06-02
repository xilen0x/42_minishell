/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:11:47 by joan              #+#    #+#             */
/*   Updated: 2024/06/02 16:30:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quote_1(char c, t_iter *iter, t_qts *quotes)
{
	if (c == '"' && quotes->d_quote == 0 && quotes->s_quote == 0)
	{
		quotes->d_quote = 1;
		iter->i++;
	}
	else if (c == '"' && quotes->d_quote == 1)
	{
		quotes->d_quote = 0;
		iter->i++;
	}
	else if (c == '\'' && quotes->s_quote == 0 && quotes->d_quote == 0)
	{
		quotes->s_quote = 1;
		iter->i++;
	}
	else if (c == '\'' && quotes->s_quote == 1)
	{
		quotes->s_quote = 0;
		iter->i++;
	}
}