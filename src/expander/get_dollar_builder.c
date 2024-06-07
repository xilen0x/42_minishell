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
	if (str[xpdr->i] == '?')//SI ES '?'
		handle_dollar_question(xpdr);
	else if (!ft_isalpha(str[xpdr->i]) && str[xpdr->i] != '_')//SI INVALID SYNTAX
		handle_dollar_invalid_syntax(str, xpdr);
	else //SI VALID SYNTAX
	{
		xpdr->key = get_env_key(str + xpdr->i);//retorna un puntero mallocado al nombre despues del '$'
		xpdr->val = get_env_val(xpdr->key, envlist);//busco su valor en el env y retorna un mallocado o un NULL si no lo hay
		xpdr->i += ft_strlen(xpdr->key);//salto el len de 'key' en el recorrido del token
		str_free_and_null(&xpdr->key);//libero 'key'
		if (xpdr->val != NULL)
			while (xpdr->val && xpdr->val[xpdr->k] != '\0')//ponemos 'val' en 'result'
			{
				xpdr->result[xpdr->j] = xpdr->val[xpdr->k];
				xpdr->j++;
				xpdr->k++;
			}
		str_free_and_null(&xpdr->val);//libera 'val'
		xpdr->k = 0;
		xpdr->i--;//para contrarestar el i++ que encontrara al volver a la funcion que lo llamó
	}
}
