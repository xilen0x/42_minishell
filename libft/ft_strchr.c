/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:38:38 by castorga          #+#    #+#             */
/*   Updated: 2023/06/15 11:14:20 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strchr(): Locates a character in a string. This finds the first occurrence
 of the desired character in a string.

 DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_to_find;

	c_to_find = c;
	while (*s != c_to_find)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

/*
int	main(void)
{
	int c = 'x';
	char str[] = "holamundo";
	printf("character found: %s\n", strchr(str, c));

	char str2[] = "holamundo";
	printf("character found: %s\n", ft_strchr(str2, c));

	return (0);
}*/
/*
output:
when int c = 'm':
character found: mundo
character found: mundo

when int c = 'x':
character found: (null)
character found: (null)
*/
