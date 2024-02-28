/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:12:31 by castorga          #+#    #+#             */
/*   Updated: 2023/06/14 15:21:29 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Asigna un carácter n veces a una parte de la memoria*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int		i;
	char				*p;

	p = (char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = (char)c;
		i++;
	}
	return (b);
}

/*
int main ()
{
	printf("\n---------memset-------------*\n");
	char str[] = "almost every programmer should know memset!";
	printf("%s\n", memset(str + 5, '*' , 3));
	printf("%s\n", (char *)memset(str, '-' , 3));

	printf("\n---------ft_memset----------*\n");
	char str2[] = "almost every programmer should know memset!";
	printf("%s", ft_memset(str + 5, '*', 3));
	printf("%s", (char *)ft_memset(str2, '-', 3));

	return 0;
}*/

/*
//In the case of ft_memset(str, '*', 3)
 0   1	 2	 3	 4	 5	 6	 7	 8	 9	10	
'*' '*' '*' 'o' 's' 't' ' ' 'e' 'v' 'e' r'  ...etc

//In the case of ft_memset(str + 5, '*', 3)
 0   1	 2	 3	 4	 5	 6	 7	 8	 9	10	
'a' 'l' 'm' 'o' 's' '*' '*' '*' 'v' 'e' r'  ...etc
*/
