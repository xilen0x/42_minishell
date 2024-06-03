/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_one_arr2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:36:23 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:36:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Makes a new copy allocated and NULL terminated of **arr_2d 
adding *str at the end. The old **arr_2d is freed.*/
char	**add_one_arr2d(char **arr2d, char *new)
{
	char	**new_arr2d;
	size_t	size;
	size_t	i;

	i = 0;
	size = size_arr2d(arr2d);
	new_arr2d = (char **)malloc((size + 2) * sizeof(char *));
	if (!new_arr2d)
		return (NULL);
	while (i < size)
	{
		new_arr2d[i] = ft_strdup(arr2d[i]);
		i++;
	}
	i--;
	new_arr2d[i] = ft_strdup(new);
	new_arr2d[i + 1] = NULL;
	return (new_arr2d);
}
