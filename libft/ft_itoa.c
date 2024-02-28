/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:53:49 by castorga          #+#    #+#             */
/*   Updated: 2023/05/30 15:53:52 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Saves the given number as a string (char array) */

/*
Prototipo 
char *ft_itoa(int n);

Parámetros 
n: el entero a convertir.

Valor devuelto 
La string que represente el número.
NULL si falla la reserva de memoria.

Funciones autorizadas
malloc

Descripción 
Utilizando malloc(3), genera una string que represente el valor entero recibido 
como argumento.
Los números negativos tienen que gestionarse.
*/
#include "libft.h"

static size_t	ft_numlen(long long n)
{
	size_t	count;

	count = 1;
	if (n <= 0)
		count++;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	if (n == 0)
		return (--count);
	return (count);
}

static char	*ft_int_to_str(long long n, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = len - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long long	num;
	size_t		len;
	char		*str;

	num = n;
	len = ft_numlen(num);
	str = ft_int_to_str(num, len);
	return (str);
}

/*
int	main(void)
{
	int number = -2147483648;
	//int number = 0;
	char *str_number = ft_itoa(number);
	printf("Number: %d\n", number);
	printf("String: %s\n", str_number);
	free(str_number);
	return (0);
}
*/