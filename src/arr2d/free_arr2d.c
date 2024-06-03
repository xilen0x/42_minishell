/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:37:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:37:17 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Frees all elements of an **arr2d included the main pointer as well.*/
void	free_arr2d(char **array_strings)
{
	size_t	i;

	if (array_strings == NULL)
		return ;
	i = 0;
	if (array_strings != NULL)
	{
		while (array_strings[i] != NULL)
		{
			free(array_strings[i]);
			array_strings[i] = NULL;
			i++;
		}
		free(array_strings);
		array_strings = NULL;
	}
}
/*//-------ALTERNATIVA DE HNOS LAJARA----------
// Frees the NULL-terminated array of strings 'arr'.
void	arrstr_free(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(arr);
}*/