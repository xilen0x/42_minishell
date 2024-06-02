/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:45:53 by joan              #+#    #+#             */
/*   Updated: 2024/06/02 16:31:32 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Handles what is found after '$' sign*/
void	handle_dollar(char *str, t_iter *iter, t_qts *quotes, t_env *envlist)
{
	char	*env_key;
	char	*env_val;

	if (str[iter->i] == '?')
		iter->len += get_exit_status_len();
	else if (!ft_isalpha(str[iter->i]) && str[iter->i] != '_')//SYNTAX NO VALIDA, SE AÑADIRA TAL CUAL
	{
		if (str[iter->i] == '\'' || str[iter->i] == '"')//SI ES COMILLA.
		{
			handle_quote_2(str[iter->i], iter, quotes);
			iter->len++;//cuento el simbolo '$' saltado arriba, porque debera mostrarse
		}
		else//SI NO ES COMILLA
			iter->len ++;//cuento el '$' y el char actual no valido, porque los deberé añadir
	}
	else //RESTA DE CASOS
	{
		env_key = get_env_key(str + iter->i);//retorna un puntero mallocado al nombre despues del '$'
		env_val = get_env_val(env_key, envlist);//busco su valor en el env y retorna un mallocado o un NULL si no lo hay
		if (env_val != NULL)
			iter->len += get_len_and_free(env_val);//calcula su len, lo libera y lo pone a NULL
		iter->i += get_len_and_free(env_key);//pilla el len y libera
		iter->i--;//para contrarestar el i++ que encontrara al volver a la funcion que lo llamó
	}
}
