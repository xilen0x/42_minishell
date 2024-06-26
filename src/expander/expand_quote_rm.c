/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:28:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/04 12:42:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Returns a *char expanded and quote removed */
char	*expander(char *str, t_env *envlist)
{
	t_xpdr	*xpdr;
	char	*res;

	xpdr = (t_xpdr *)malloc(sizeof(t_xpdr));
	init_xpdr(xpdr);
	xpdr->len = new_tok_len(str, xpdr, envlist);
	xpdr->result = (char *)p_malloc(sizeof(char) * (xpdr->len + 1));
	init_xpdr_except_result(xpdr);
	new_tok_builder(str, xpdr, envlist);
	res = ft_strdup(xpdr->result);
	free(xpdr->result);
	free(xpdr);
	return (res);
}
