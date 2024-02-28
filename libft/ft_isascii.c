/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:01:57 by castorga          #+#    #+#             */
/*   Updated: 2023/05/09 12:02:01 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns whether or not a value belongs to the ASCII table*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	c;
	char	d;

	c = 2;
	d = 128;
	printf("\nWhen assci is passed: %d", isascii(c));
	printf("\nWhen non-assci is passed: %d", isascii(d));
	printf("\n-------\n");
	printf("\nWhen assci is passed: %d", ft_isascii(c));
	printf("\nWhen non-assci is passed: %d\n", ft_isascii(d));
	return (0);
}
*/