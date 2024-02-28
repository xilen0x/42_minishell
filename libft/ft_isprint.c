/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:01:21 by castorga          #+#    #+#             */
/*   Updated: 2023/05/09 12:01:25 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns whether a character is printable*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	int	c;
	int d;

	c = '2';
	d = 9;
	printf("\n---isprint----");
	printf("\nWhen printable is passed: %d", isprint(c));
	printf("\nWhen non-printable is passed: %d\n", isprint(d));
	printf("\n---ft_isprint----");
	printf("\nWhen printable is passed: %d",   ft_isprint(c));
	printf("\nWhen non-printable is passed: %d\n", ft_isprint(d));
	return (0);
}*/