/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:05:19 by castorga          #+#    #+#             */
/*   Updated: 2023/05/19 16:05:22 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reads a String, and, after ignoring spaces with ft_isspace, saves the string 
into an integer*/

/*
DESCRIPTION
     The atoi() function converts the initial portion of the string pointed to
     by str to int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

IMPLEMENTATION NOTES
     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.

     The strtol() and strtol_l() functions are recommended instead of atoi()
     and atoi_l() functions, especially in new code.
*/

#include "libft.h"

static char	*ft_isspace(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	return (str);
}

int	ft_atoi(const char *str)
{
	short int	parity;
	int			number;
	char		*mystr;

	parity = 0;
	number = 0;
	mystr = ft_isspace((char *)str);
	if (*mystr == '+' || *mystr == '-')
	{
		if (*mystr == '-')
			parity++;
		mystr++;
	}
	while (*mystr >= '0' && *mystr <= '9')
	{
		number *= 10;
		number += *mystr - '0';
		mystr++;
	}
	if (parity % 2 == 0)
		return (number);
	return (-number);
}

/*
int	main(void)
{
	char	*s = "+-54";
	//const char *s = "   ---+--+1234ab567";

	printf("%d\n", ft_atoi(s));
	return (0);
}
*/
