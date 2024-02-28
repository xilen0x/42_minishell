/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:46:42 by castorga          #+#    #+#             */
/*   Updated: 2023/05/24 15:46:45 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parámetros 
s1: La string que debe ser recortada.
set: Los caracteres a eliminar de la string.

Valor devuelto
La string recortada.
NULL si falla la reserva de memoria.

Descripción
Elimina todos los caracteres de la string ’set’ desde el principio y desde
el final de ’s1’, hasta encontrar un caracter no perteneciente a ’set’. 
La string resultante se devuelve con una reserva de malloc(3)
*/

#include "libft.h"

/* F. que verifica si un carácter está presente en un conjunto de caracteres.*/
static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len;
	unsigned int	i;
	const char		*start;
	const char		*end;
	char			*reserved;

	i = 0;
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (ft_isset(*start, set))
		start++;
	while (start <= end && ft_isset(*end, set))
		end--;
	len = end - start + 1;
	reserved = (char *)malloc((len + 1) * sizeof(char));
	if (reserved == NULL)
		return (NULL);
	while (i < len)
	{
		reserved[i] = start[i];
		i++;
	}
	reserved[len] = '\0';
	return (reserved);
}

/*
int	main(void)
{
	printf("***%s***\n", ft_strtrim(" holamundo ", " "));
	printf("***%s***\n", ft_strtrim("           ", " "));
	return (0);
}
*/
/*
castorga@car15s6 project01 % cc -Wextra -Werror -Wall ft_strtrim.c ft_strlen.c
castorga@car15s6 project01 % ./a.out 
***holamundo***
******
*/