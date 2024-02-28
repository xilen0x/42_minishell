/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:47:39 by castorga          #+#    #+#             */
/*   Updated: 2023/06/14 12:34:23 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.

RETURN VALUES
     The memcmp() function returns zero if the two strings are identical, oth-
     erwise returns the difference between the first two differing bytes
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	unsigned int		i;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*

int	main(void)
{
	printf("\n--------- memcmp ---------\n");
	printf("%d\n", memcmp("test", "testss", 7));
	printf("%d\n", memcmp("testss", "test", 7));
	printf("%d\n", memcmp("", "test", 4));
	printf("%d\n", memcmp("test", "", 4));
	printf("%d\n", memcmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", memcmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", memcmp("test\200", "test\0", 6));
	
	printf("\n--------- ft_memcmp ---------\n");
	printf("%d\n", ft_memcmp("test", "testss", 7));
	printf("%d\n", ft_memcmp("testss", "test", 7));
	printf("%d\n", ft_memcmp("", "test", 4));
	printf("%d\n", ft_memcmp("test", "", 4));
	printf("%d\n", ft_memcmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", ft_memcmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", ft_memcmp("test\200", "test\0", 6));
}*/
