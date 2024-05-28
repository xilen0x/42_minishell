/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_arr2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:36:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:36:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Counts the number of elements contained in a 2d array*/
size_t	size_arr2d(char **arr2d)
{
	size_t	size;

	size = 0;
	while (arr2d && arr2d[size])
		size++;
	return (size);
}
