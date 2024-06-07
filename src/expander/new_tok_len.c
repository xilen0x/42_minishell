/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tok_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:08:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 16:26:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns the token length once expanded and quote removed if it applies*/
size_t	new_tok_len(char *str, t_xpdr *xpdr, t_env *envlist)
{
	while (str && str[xpdr->i])
	{
		if (str[xpdr->i] == '"' || str[xpdr->i] == '\'')
			handle_quote_len(str[xpdr->i], xpdr);
		else if (str[xpdr->i] == '$' && xpdr->s_quote == CLOSED \
			&& str[xpdr->i + 1])
		{
			xpdr->i++;
			get_dollar_len(str, xpdr, envlist);
			xpdr->i++;
		}
		else
		{
			xpdr->len++;
			xpdr->i++;
		}
	}
	return (xpdr->len);
}
