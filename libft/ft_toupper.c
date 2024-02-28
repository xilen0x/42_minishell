/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:32:34 by castorga          #+#    #+#             */
/*   Updated: 2023/05/15 11:32:37 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
The toupper() function converts a lower-case letter to the corresponding
upper-case letter.  The argument must be representable as an unsigned
char or the value of EOF.
RETURN VALUES
If the argument is a lower-case letter, the toupper() function returns
the corresponding upper-case letter if there is one; otherwise, the argu-
ment is returned unchanged.*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

/*#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", toupper('a'));
	return (0);
}
*/