/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:48:27 by castorga          #+#    #+#             */
/*   Updated: 2023/05/09 16:48:30 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Writes n zeroes in the string s */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*p;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	s[] = "+-54";
	size_t	n = 10;
	ft_bzero((void *)s, n);
	printf(":%s:\n", s);
    
    char str[20] = "Hola, mundo!";
	printf("Antes de ft_bzero: %s\n", str);
    ft_bzero(str, sizeof(str));
    printf("Después de ft_bzero: %s\n", str);
	
	return (0);
}
*/
