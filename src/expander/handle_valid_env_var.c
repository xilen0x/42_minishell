/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_valid_env_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:03:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/31 18:04:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	handle_valid_env_var(char *str, t_len *len, t_env *envlist)
{
	char	*env_key;
	char	*env_val;

	env_key = get_env_key(str + len->i);
	env_val = get_env_val(env_key, envlist);
	if (env_val != NULL)
		len->len += get_len_and_free(env_val);//ENTREGA EL LEN DEL VALOR DE LA VARIABLE
	len->i += get_len_and_free(env_key);//ENTREGA EL LEN DEL NOMBRE DE LA VARIABLE
	return (len->i);
}
