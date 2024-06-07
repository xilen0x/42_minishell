/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tok_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:29:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 16:25:43 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---Returns the new token already expanded and quote removed---*/
void	*new_tok_builder(char *str, t_xpdr *xpdr, t_env *envlist)
{
	while (str && str[xpdr->i])
	{
		if (str[xpdr->i] == '"' || str[xpdr->i] == '\'')
			handle_quote_builder(str[xpdr->i], xpdr);
		else if (str[xpdr->i] == '$' && xpdr->s_quote == CLOSED \
			&& str[xpdr->i + 1])
		{
			xpdr->i++;
			get_dollar_builder(str, xpdr, envlist);
			xpdr->i++;
		}
		else
		{
			xpdr->result[xpdr->j] = str[xpdr->i];
			xpdr->j++;
			xpdr->i++;
		}
	}
	xpdr->result[xpdr->j] = '\0';
	str_free_and_null(&str);
	return (xpdr->result);
}
