/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_invalid_env_var.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:05:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/02 16:31:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Retorna el length de la variable sintacticamente NO valida  */
size_t	handle_invalid_env_var(char *str, t_iter *len, t_qts *quotes)
{
	if (str[len->i] == '\'' || str[len->i] == '"')
	{
		handle_quotes(str[len->i], quotes, len);
		(len->len)++;
	}
	else
		len->len += 2;//cuento el '$' y el char actual no valido, porque los deberé añadir al nuevo token
	return (len->i);
}
