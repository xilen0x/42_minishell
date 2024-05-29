/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:32:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:36:39 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns the allocated value of env_key if found in envlist, otherwise NULL
 is returned.*/
char	*get_env_val(char *env_key, t_env *envlist)
{
	char	*val_aux;

	val_aux = NULL;
	if (env_key == NULL)//protect por si despues de $ hay un num o especial
		return (NULL);
	while (envlist)
	{
		if (ft_strcmp(envlist->key, env_key) == 0)
		{
			val_aux = ft_strdup(envlist->val);
			return (val_aux);
		}
		envlist = envlist->next;
	}
	return (val_aux);
}
