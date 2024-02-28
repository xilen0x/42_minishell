/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:34:46 by castorga          #+#    #+#             */
/*   Updated: 2023/05/15 13:34:49 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

/*#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", tolower('a'));
	return (0);
}
*/