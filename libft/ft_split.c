/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:11:11 by castorga          #+#    #+#             */
/*   Updated: 2023/09/15 11:56:45 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo
char **ft_split(char const *s, char c);

Parámetros
s: La string a separar.
c: El carácter delimitador.

Valor devuelto
El array de nuevas strings resultante de la separación.
NULL si falla la reserva de memoria.

Funciones autorizadas
malloc, free

Descripción
Reserva (con malloc) un array de strings, resultante de separar
la string ’s’ en substrings, utilizando el caracter ’c’ como delimitador.
El array debe terminar con un puntero NULL.
*/

#include "libft.h"
/* función q calcula la long real de un string(salta los c repetidos a 'c').*/
static size_t	ft_real_strlen(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			++counter;
			while (*s && (*s != c))
				++s;
		}
		else
			++s;
	}
	return (counter);
}

static void	ft_free_split(char **array_strings)
{
	size_t	i;

	i = 0;
	if (array_strings)
	{
		while (array_strings[i])
		{
			free(array_strings[i]);
			i++;
		}
		free(array_strings);
	}
}

static char	**ft_process(const char *s, char c, char **array_strings)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while ((*s) && (*s != c) && (++len))
				++s;
			array_strings[i] = ft_substr(s - len, 0, len);
			if (!array_strings[i])
			{
				ft_free_split(array_strings);
				return (NULL);
			}
			i++;
		}
		else
			++s;
	}
	array_strings[i] = (NULL);
	return (array_strings);
}

char	**ft_split(const char *s, char c)
{
	char	**array_strings;

	if (!s)
		return (0);
	array_strings = malloc(sizeof(char *) * (ft_real_strlen(s, c) + 1));
	if (!array_strings)
		return (0);
	array_strings = ft_process(s, c, array_strings);
	return (array_strings);
}


/*int	main(void)
{
	char *str0 = "1";
	int character = ' ';
	char **result = ft_split(str0, character);

	//char *str1 = "      split       this for   me  !       ";
	//printf("Se espera: , 'split', 'this', 'for', 'me', '!'\n");
	//char **result1 = ft_split(str1, character);

	//char *str2 = "                  olol";
	//printf("Se espera: , 'olol'\n");
	//char **result2 = ft_split(str2, character);

	if (result)
	{
		size_t i = 0;
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
	}
    return (0);
}*/
