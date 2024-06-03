/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tok_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:29:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/03 18:25:43 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---Returns the new token already expanded and quote removed---*/
void	*new_tok_builder(char *str, t_xpdr *xpdr, t_env *envlist)
{
	while (str && str[xpdr->i])
	{
		if (str[xpdr->i] == '"' || str[xpdr->i] == '\'')//gestiona las comillas
			handle_quote(str[xpdr->i], xpdr);
		else if (str[xpdr->i] == '$' && xpdr->s_quote == CLOSED \
			&& str[xpdr->i + 1])//gestiona '$'
		{
			xpdr->i++;//salto el '$'
			get_dollar_expansion(str, xpdr, envlist);
			xpdr->i++;//crec que va aqui l'increment si comparo amb new_tok_len
		}
		else
		{
			xpdr->result[xpdr->j] = str[xpdr->i];
			xpdr->j++;
			xpdr->i++;//diria que aquest increment tambe va aqui
		}
	}
	xpdr->result[xpdr->j] = '\0';//ya tengo el nuevo token expandido en result
	str_free_and_null(&str);//libero el token pre-expansion
	return (xpdr->result);//retorno el token acabado y mallocado
}