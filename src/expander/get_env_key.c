/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:38:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/03 14:29:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns an allocated var name, or NULL if str is NULL.
It does not take into account whether or not it exists on the env.*/
char	*get_env_key(char *str)
{
	size_t	i;
	char	*var_name;

	i = 0;
	var_name = NULL;
/*SI CARACT VALIDS PARA UNA VAR DE ENTORNO, CUENTA, RESERVA MEMORIA Y RELLENA*/
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i > 0)
	{
		var_name = (char *)p_malloc(sizeof(char) * (i + 1));
		ft_strlcpy(var_name, str, i + 1);
	}
	return (var_name);
}
/*SI HAY CARACTERES QUE NO SON ', ", $, \0, ME LOS LLEVO
	while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$')
		i++;
	if (i > 0)
	{
		var_name = (char *)p_malloc(sizeof(char) * (i + 1));
		ft_strlcpy(var_name, str, i + 1);
	}
	return (var_name);*/