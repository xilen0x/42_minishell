/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:52:36 by castorga          #+#    #+#             */
/*   Updated: 2023/05/17 10:52:40 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memchr() function locates the first occurrence of c (converted to an
     unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located, or NULL if
     no such byte exists within n bytes.
*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*my_string;
	unsigned char		c_to_find;
	unsigned int		i;

	my_string = (const unsigned char *)s;
	c_to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*my_string == c_to_find)
			return ((void *)my_string);
		my_string++;
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	printf("Test 1\n");
	printf("Result memchr   : %s\n", memchr(" ", '-', 1));
	printf("Result ft_memchr: %s\n", ft_memchr(" ", '-', 1));

	printf("Test 2\n");
	printf("Result memchr   : %s\n", memchr("", '-', 1));
	printf("Result ft_memchr: %s\n", ft_memchr("", '-', 1));

	printf("Test 3\n");
	printf("Result memchr   : %s\n", memchr("holamundo", 'm', 10));
	printf("Result ft_memchr: %s\n", ft_memchr("holamundo", 'm', 10));

	printf("Test 4\n");
	printf("Result memchr   : %s\n", memchr("holamundo", 'x', 10));
	printf("Result ft_memchr: %s\n", ft_memchr("holamundo", 'x', 10));

	printf("Test 5\n");
	printf("Result memchr   : %s\n", memchr("holamundo", 'm', 2));
	printf("Result ft_memchr: %s\n", ft_memchr("holamundo", 'm', 2));
	return (0);
}
*/