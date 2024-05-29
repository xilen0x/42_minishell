/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_rm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:29:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:31:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Returns a *char expanded and the quote removed */
char	*expand_quote_rm(char *str, t_env *envlist)
{
	char	*result;
	size_t	len;

	result = NULL;
	len = new_tok_len(str, envlist);//len de token, sin comillas y expandido
	result = (char *)p_malloc(sizeof(char) * (len + 1));
	result = new_tok_builder(str, envlist, result);//crea y rellena un nuevo token y borra y libera el antiguo
	return (result);
}
