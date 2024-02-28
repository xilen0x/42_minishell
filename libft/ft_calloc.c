/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:01:43 by castorga          #+#    #+#             */
/*   Updated: 2023/05/22 16:01:46 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
	 allocate memory.  The allocated memory is aligned such that it can be used
	 for any data type. 

     The calloc() function contiguously allocates enough space for count 
	 objects that are size bytes of memory each and returns a pointer to the 
	 allocated memory. The allocated memory is filled with bytes of value zero.
	
	 When extending a region allocated with calloc(3), realloc(3) does not
     guarantee that the additional memory is also zero-filled.

RETURN VALUES
     If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and
     aligned_alloc() functions return a pointer to allocated memory.  If 
	 there is an error, they return a NULL pointer and set errno to ENOMEM.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*space_reserved;

	space_reserved = malloc(size * count);
	if (!space_reserved)
		return (0);
	else
	{
		ft_bzero(space_reserved, size * count);
		return (space_reserved);
	}
}

/*int	main(void)
{
	printf(":%s:\n", calloc(10, 4));
	printf(":%s:\n", ft_calloc(10, 4));
	return (0);
}
*/

/*
% cc ft_calloc.c ft_bzero.c
% ./a.out                  
::
::
*/