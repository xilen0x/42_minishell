/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_rm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:28:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/04 12:42:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Returns a *char expanded and quote removed */
char	*expand_quote_rm(char *str, t_env *envlist)
{
	t_xpdr	*xpdr;
	char	*res;

 	xpdr = (t_xpdr *)malloc(sizeof(t_xpdr));
	init_xpdr(xpdr);
	xpdr->len = new_tok_len(str, xpdr, envlist);//len del token, quote removed y expandido
	xpdr->result = (char *)p_malloc(sizeof(char) * (xpdr->len + 1));
	init_xpdr_except_result(xpdr);
	new_tok_builder(str, xpdr, envlist);//rellena el nuevo token expandido y libera el antiguo
	res = ft_strdup(xpdr->result);//copia mallocada de result para retornar y poder borrar xpdr
	free(xpdr->result);
	free(xpdr);
	return (res);
}
