/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:04:19 by castorga          #+#    #+#             */
/*   Updated: 2023/05/03 17:04:22 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns 1 if the input is a number in the ASCII table*/

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	char	c, d;

	c = '2';
	d = 'a';
	printf("\nWhen digit is passed: %d", isdigit(c));
	printf("\nWhen non-digit is passed: %d", isdigit(d));
	printf("\n-------\n");
	printf("\nWhen digit is passed: %d", ft_isdigit(c));
	printf("\nWhen non-digit is passed: %d", ft_isdigit(d));
	return (0);
}
*/