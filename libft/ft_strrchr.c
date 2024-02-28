/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:37:26 by castorga          #+#    #+#             */
/*   Updated: 2023/06/15 14:03:14 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c.*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*found;

	found = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			found = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		found = ((char *)s);
	return (found);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int c = 'm';
	char str[] = "holamundo";
	printf("character found: %s\n", strrchr(str, c));
	printf("in the position: %ld\n", (strrchr(str, c) - str));

	char str2[] = "holamundo";
	printf("character found: %s\n", ft_strrchr(str2, c));
	printf("in the position: %ld\n", (ft_strrchr(str2, c) - str2));

	return (0);
}*/
