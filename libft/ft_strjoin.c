/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:41:52 by castorga          #+#    #+#             */
/*   Updated: 2023/06/15 12:52:48 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
char *ft_strjoin(char const *s1, char const *s2);

Parámetros 
s1: La primera string.
s2: La string a añadir a ’s1’.

Valor devuelto
La nueva string.
NULL si falla la reserva de memoria.

Funciones autorizadas
malloc

Descripción 
Reserva (con malloc) y devuelve una nueva string, formada por la 
concatenación de ’s1’ y ’s2’.
*/

#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*space_reserved;
	unsigned int	len_s1;
	unsigned int	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 == 0 && s2 == 0)
		return (0);
	space_reserved = malloc((len_s1 + len_s2) + 1);
	if (!space_reserved)
		return (0);
	else
	{
		ft_strncpy(space_reserved, (char *)s1, len_s1);
		ft_strncpy(space_reserved + len_s1, (char *)s2, len_s2);
		space_reserved[len_s1 + len_s2] = '\0';
		return (space_reserved);
	}
}

/*int	main(void)
{
	char		dst[20] = "Hello ";
	const char	src[] = "World!";

	printf("%s", ft_strjoin(dst, src));
	//printf("%s\n", ft_strjoin("", ""));
	return (0);
}*/
