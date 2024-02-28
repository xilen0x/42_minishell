/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:23:46 by castorga          #+#    #+#             */
/*   Updated: 2023/06/02 12:23:51 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(Applies a function (mapping) to every element in a string)

Prototipo 
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

Parámetros 
s: La string que iterar.
f: La función a aplicar sobre cada carácter.

Valor devuelto 
La string creada tras el correcto uso de ’f’ sobre cada carácter.
NULL si falla la reserva de memoria.

Funciones autorizadas
malloc

Descripción 
A cada carácter de la string ’s’, aplica la función ’f’ dando como 
parámetros el índice de cada carácter dentro de ’s’ y el propio carácter. 
Genera una nueva string con el resultado del uso sucesivo de ’f’
*/
/*
static char	xtoupper(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}

/*
int	main(void)
{
	const char *str = "Hello, World!";
	char *result = ft_strmapi(str, &xtoupper);

	if (result)
	{
		printf("Original string		: %s\n", str);
		printf("Transformed string	: %s\n", result);
		free(result);
	}
	else
		printf("Error: Failed to allocate memory.\n");
	return (0);
}
*/