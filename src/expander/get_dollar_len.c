/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:45:53 by joan              #+#    #+#             */
/*   Updated: 2024/06/07 16:21:51 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---Returns the lenght of what is found after '$' sign---*/
void	get_dollar_len(char *str, t_xpdr *xpdr, t_env *envlist)
{
	if (str[xpdr->i] == '?')
		xpdr->len += get_exit_status_len();
	else if (!ft_isalpha(str[xpdr->i]) && str[xpdr->i] != '_')
	{
		if (str[xpdr->i] == '\'' || str[xpdr->i] == '"')
		{
			handle_quote_after_dollar(str[xpdr->i], xpdr);
			xpdr->len++;
		}
		else
			xpdr->len += 2;
	}
	else
	{
		xpdr->key = get_env_key(str + xpdr->i);
		xpdr->val = get_env_val(xpdr->key, envlist);
		if (xpdr->val != NULL)
			xpdr->len += get_len_and_free(xpdr->val);
		xpdr->i += get_len_and_free(xpdr->key);
		xpdr->i--;
	}
}
