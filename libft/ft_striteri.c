/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:07:52 by castorga          #+#    #+#             */
/*   Updated: 2023/06/12 14:07:54 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
void ft_striteri(char *s, void (*f)(unsigned int, char*));

Parámetros 
s: La string que iterar.
f: La función a aplicar sobre cada carácter.

Valor devuelto 
Nada

Funciones autorizadas
Ninguna

Descripción
A cada carácter de la string ’s’, aplica la función
’f’ dando como parámetros el índice de cada
carácter dentro de ’s’ y la dirección del propio
carácter, que podrá modificarse si es necesario.
*/

#include "libft.h"

/*
#include <ctype.h>

static void	transform_char(unsigned int index, char *c)
{
	*c = ft_toupper(*c);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

/*
int	main(void)
{
	const char *str = "hello, world!";
	char *result = ft_strdup(str); // Create a copy of the original string

	ft_striteri(result, &transform_char);

	printf("Original string     : %s\n", str);
	printf("Transformed string  : %s\n", result);
	free(result);

	return (0);
}
*/
/*$ ./a.out
Original string     : hello, world!
Transformed string  : HELLO, WORLD!
*/
