/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:01:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/31 18:04:33 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Gestiona lo que encuentra despues de '$', segun sea expansionable, invalid 
syntax o '$?'*/
size_t	handle_dollar(char *str, t_len *len, t_env *envlist, t_qts *quotes)
{
	len->i++;
	if (str[len->i] != '?' && !ft_isalpha(str[len->i]) && str[len->i] != '_')//SI ES UNA VAR CON INVALID SYNTAX
		len->i = handle_invalid_env_var(str, len, quotes);
	else if (str[len->i] == '?')//SI ES UN $?
		len->len += get_exit_status_len();
	else//SI ES UNA VAR CON VALID SYNTAX
	{
		len->i = handle_valid_env_var(str, len, envlist);
		len->i--;
	}
	return (len->i);
}
