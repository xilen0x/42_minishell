/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_arr2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:37:23 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:37:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns an allocated and NULL terminated copy of **arr_2d*/
char	**dup_arr2d(char **arr2d)
{
	char	**env;
	int		size;
	int		i;

	i = 0;
	size = size_arr2d(arr2d);
	env = (char **)p_malloc((size + 1) * sizeof(char *));
	while (i < size)
	{
		env[i] = ft_strdup(arr2d[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}
