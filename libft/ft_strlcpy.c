/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:23:17 by castorga          #+#    #+#             */
/*   Updated: 2023/06/15 13:14:21 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies n - 1 bytes from a source string to a destination string*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	j;

	count = 0;
	j = 0;
	while (src[count])
		count++;
	if (size == 0)
		return (count);
	while ((j < size - 1) && (j < count))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (count);
}
/*
#include <stdio.h>
#include <string.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size);

int main() {
    char src[] = "Hola, mundo!";
    char dst[20];

    size_t copied = ft_strlcpy(dst, src, sizeof(dst));

    printf("Cadena copiada: %s\n", dst);
    printf("Número de caracteres copiados: %zu\n", copied);

    return 0;
}
*/

/*
int	main(void)
{
	const char	*src = "welcome";
	char		dst[8];
	printf("-------strlcpy------------\n");
	printf("%zu\n", strlcpy(dst, src, sizeof(dst)));

	const char	*src2 = "welcome";
	char		dst2[8];
	printf("-------ft_strlcpy------------\n");
	printf("%ld\n", ft_strlcpy(dst2, src2, sizeof(dst2)));
}
*/

/* 
-------strlcpy------------
7
-------ft_strlcpy------------
7
*/
