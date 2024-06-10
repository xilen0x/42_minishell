/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:51:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:51:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Allocates 'size' bytes of memory and returns a pointer to it.
Exits properly if memory allocation fails.*/
void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		write(2, "Error: memory allocation failure\n", 33);
		exit (EXIT_FAILURE);
	}
	return (ptr);
}
