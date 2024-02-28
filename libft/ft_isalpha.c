/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:26:12 by castorga          #+#    #+#             */
/*   Updated: 2023/05/03 13:41:57 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns 1 if the input is a letter in the ASCII table*/

int	ft_isalpha(int arg)
{
	if ((arg >= 'A' && arg <= 'Z') || (arg >= 'a' && arg <= 'z'))
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	char	c, d, e;

	c = 'Q';
	d = 'q';
	e = '+';
	printf("\nWhen uppercase alphabet is passed: %d", isalpha(c));
	printf("\nWhen lowercase alphabet is passed: %d", isalpha(d));
	printf("\nWhen non-alphabetic character is passed: %d", isalpha(e));
	printf("\n-------\n");
	printf("\nWhen uppercase alphabet is passed: %d", ft_isalpha(c));
	printf("\nWhen lowercase alphabet is passed: %d", ft_isalpha(d));
	printf("\nWhen non-alphabetic character is passed: %d", ft_isalpha(e));
	return (0);
}
*/