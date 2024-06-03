/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_rm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:28:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/03 18:27:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Returns a *char expanded and quote removed */
char	*expand_quote_rm(char *str, t_env *envlist)
{
	t_xpdr	*xpdr;

	init_xpdr(xpdr);
	xpdr->len = new_tok_len(str, envlist, xpdr);//len del token, quote removed y expandido
	xpdr->result = (char *)p_malloc(sizeof(char) * (xpdr->len + 1));
	init_xpdr_except_result(xpdr);
	new_tok_builder(str, envlist, xpdr);//rellena el nuevo token expandido y libera el antiguo
	return (xpdr->result);
}
