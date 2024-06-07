/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:38:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 14:52:35 by jocuni-p         ###   ########.fr       */
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
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))//Si caracter es valido, cuenta, malloca, rellena
		i++;
	if (i > 0)
	{
		var_name = (char *)p_malloc(sizeof(char) * (i + 1));
		ft_strlcpy(var_name, str, i + 1);
	}
	return (var_name);
}
