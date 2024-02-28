/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:23:37 by castorga          #+#    #+#             */
/*   Updated: 2023/05/04 10:23:41 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns 1 if the input is a number or a letter in the ASCII table*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		return (1);
	return (0);
}

/*int	main(void)
{
	char	c = 'a';
	char	d = '7';
	char	e = '#';

	printf("\n---------- isalnum ----------\n");
	printf("%d\n", isalnum(c));
	printf("%d\n", isalnum(d));
	printf("%d\n", isalnum(e));
	printf("\n---------- ft_isalnum ----------\n");
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", ft_isalnum(d));
	printf("%d\n", ft_isalnum(e));
	return (0);
}*/