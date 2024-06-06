/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:45:53 by joan              #+#    #+#             */
/*   Updated: 2024/06/06 10:40:59 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---Returns the lenght of what is found after '$' sign---*/
void	get_dollar_len(char *str, t_xpdr *xpdr, t_env *envlist)
{
	if (str[xpdr->i] == '?')
		xpdr->len += get_exit_status_len();
	else if (!ft_isalpha(str[xpdr->i]) && str[xpdr->i] != '_')//SI INVALID SYNTAX, SE AÑADIRA TAL CUAL
	{
		if (str[xpdr->i] == '\'' || str[xpdr->i] == '"')//SI ES COMILLA.
		{
			handle_quote_after_dollar(str[xpdr->i], xpdr);
			xpdr->len++;//cuento el simbolo '$' saltado arriba, porque debera mostrarse
		}
		else//SI NO ES COMILLA
			xpdr->len += 2;//cuento el '$' y el char actual no valido, porque los deberé añadir
	}
	else //SI VALID SYNTAX
	{
		xpdr->key = get_env_key(str + xpdr->i);//retorna un puntero mallocado al nombre despues del '$'
		xpdr->val = get_env_val(xpdr->key, envlist);//busco su valor en el env y retorna un mallocado o un NULL si no lo hay
		if (xpdr->val != NULL)
			xpdr->len += get_len_and_free(xpdr->val);//calcula su len, lo libera y lo pone a NULL
		xpdr->i += get_len_and_free(xpdr->key);//pilla el len y libera
		xpdr->i--;//para contrarestar el i++ que encontrara al volver a la funcion que lo llamó
	}
}
