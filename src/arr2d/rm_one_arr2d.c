/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_one_arr2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:37:02 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:42:22 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns a mallocated copy of arr2d with the index element removed. 
Frees the original array. 
Arguments: the arr2d and the index of the element to be deleted. 
In case of memory failure, it returns NULL. */
char	**rm_one_arr2d(char **arr2d, int index)
{
	char	**new_arr2d;
	char	**tmp_arr2d;
	size_t	size;
	int		i;

	i = 0;
	tmp_arr2d = arr2d;
	size = size_arr2d(arr2d);
	new_arr2d = (char **)p_malloc(size * sizeof(char *));
	while (i < index)
	{
		new_arr2d[i] = ft_strdup(tmp_arr2d[i]);
		i++;
	}
	while (tmp_arr2d[i + 1])
	{
		new_arr2d[i] = ft_strdup(tmp_arr2d[i + 1]);
		i++;
	}
	new_arr2d[i] = NULL;
	free_arr2d(arr2d);
	return (new_arr2d);
}
