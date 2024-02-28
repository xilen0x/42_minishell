/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:26:07 by castorga          #+#    #+#             */
/*   Updated: 2023/06/15 13:44:39 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-termi-
     nated string needle in the string haystack, where not more than len char-
     acters are searched.  Characters that appear after a `\0' character are
     not searched.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	k;
	size_t	i;
	size_t	j;

	k = 0;
	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (needle[k] != '\0')
		k++;
	while ((haystack[i] != '\0') && (i + k <= len))
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
//#include <stddef.h>
/*
#include <stdio.h>

int main(void)
{
	printf("\n--------- strnstr ---------\n");
    printf("%s\n", strnstr("Foo Bar Baz", "Bar", 4));
	printf("%s\n", strnstr("Foo Bar Baz", "Bar", 11));
	printf("%s\n", strnstr("", "Bar", 1));
	printf("%s\n", strnstr("Foo Bar Baz", "x", 11));
	printf("%s\n", strnstr("xdcxdc", "Bar", 11));

	printf("\n--------- ft_strnstr ---------\n");
    printf("%s\n", ft_strnstr("Foo Bar Baz", "Bar", 4));
	printf("%s\n", ft_strnstr("Foo Bar Baz", "Bar", 11));
	printf("%s\n", ft_strnstr("", "Bar", 1));
	printf("%s\n", ft_strnstr("Foo Bar Baz", "x", 11));
	printf("%s\n", ft_strnstr("xdcxdc", "Bar", 11));

	return (0);
}
*/
