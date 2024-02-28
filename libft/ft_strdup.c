/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:04:57 by castorga          #+#    #+#             */
/*   Updated: 2023/05/23 10:04:59 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer may
     subsequently be used as an argument to the function free(3).
     If insufficient memory is available, NULL is returned and errno is set to
     ENOMEM.

RETURN VALUE
       On  success,  the strdup() function returns a pointer to the duplicated
       string.  It returns NULL if insufficient memory was available, with er‐
       rno set to indicate the cause of the error.

*/
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*space_reserved;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1);
	space_reserved = malloc(len + 1);
	if (!space_reserved)
		return (0);
	else
	{
		while (*s1)
		{
			space_reserved[i++] = *s1++;
		}
		space_reserved[i] = '\0';
		return (space_reserved);
	}
}

/*
int	main(void)
{
	printf(":%s:\n", strdup("holamundo"));
	printf(":%s:\n", ft_strdup("holamundo"));
	return (0);
}
*/
/*
castorga@car15s2 project01 % cc ft_strdup.c ft_strlen.c
castorga@car15s2 project01 % ./a.out                   
:holamundo:
:holamundo:
*/