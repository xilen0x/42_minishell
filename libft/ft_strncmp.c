/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:10:59 by castorga          #+#    #+#             */
/*   Updated: 2023/06/15 13:26:22 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Compares two strings up to the n-th character*/
/*
DESCRIPTION
     The strcmp() and strncmp() functions lexicographically compare the null-
     terminated strings s1 and s2.

     The strncmp() function compares not more than n characters.  Because
     strncmp() is designed for comparing strings rather than binary data,
     characters that appear after a `\0' character are not compared.

RETURN VALUES
     The strcmp() and strncmp() functions return an integer greater than,
     equal to, or less than 0, according as the string s1 is greater than,
     equal to, or less than the string s2.
*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
		{
			if (c1 > c2)
				return (1);
			else
				return (-1);
		}
		else if (c1 == '\0')
			return (0);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("\n--------- strncmp ---------\n");
	printf("%d\n", strncmp("test", "testss", 7));
	printf("%d\n", strncmp("testss", "test", 7));
	printf("%d\n", strncmp("", "test", 4));
	printf("%d\n", strncmp("test", "", 4));
	printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", strncmp("test\200", "test\0", 6));
	
	printf("\n--------- ft_strncmp ---------\n");
	printf("%d\n", ft_strncmp("test", "testss", 7));
	printf("%d\n", ft_strncmp("testss", "test", 7));
	printf("%d\n", ft_strncmp("", "test", 4));
	printf("%d\n", ft_strncmp("test", "", 4));
	printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));

}
*/
