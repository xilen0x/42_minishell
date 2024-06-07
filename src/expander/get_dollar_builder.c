/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar_builder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:48:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/04 17:54:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Handles what is found after '$' sign*/
void	get_dollar_builder(char *str, t_xpdr *xpdr, t_env *envlist)
{
	if (str[xpdr->i] == '?')
		handle_dollar_question(xpdr);
	else if (!ft_isalpha(str[xpdr->i]) && str[xpdr->i] != '_')
		handle_dollar_invalid_syntax(str, xpdr);
	else
	{
		xpdr->key = get_env_key(str + xpdr->i);
		xpdr->val = get_env_val(xpdr->key, envlist);
		xpdr->i += ft_strlen(xpdr->key);
		str_free_and_null(&xpdr->key);
		if (xpdr->val != NULL)
		{
			while (xpdr->val && xpdr->val[xpdr->k] != '\0')
			{
				aux = xpdr->val[xpdr->k];
				xpdr->result[xpdr->j] = aux;
				xpdr->j++;
				xpdr->k++;
			}
		}
		str_free_and_null(&xpdr->val);
		xpdr->k = 0;
		xpdr->i--;
	}
}
