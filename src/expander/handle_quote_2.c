/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:38:42 by joan              #+#    #+#             */
/*   Updated: 2024/06/02 16:30:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quote_2(char c, t_iter *iter, t_qts *quotes)
{
	if (c == '"' && quotes->d_quote == 0 && quotes->s_quote == 0)
		quotes->d_quote = 1;
	else if (c == '"' && quotes->d_quote == 1)
		quotes->d_quote = 0;
	else if (c == '\'' && quotes->s_quote == 0 && quotes->d_quote == 0)
		quotes->s_quote = 1;
	else if (c == '\'' && quotes->s_quote == 1)
		quotes->s_quote = 0;
}
