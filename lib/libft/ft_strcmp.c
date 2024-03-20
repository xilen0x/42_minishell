/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:50 by castorga          #+#    #+#             */
/*   Updated: 2023/04/17 13:11:34 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] > s2[i])
	{
		return (1);
	}
	else if (s1[i] == s2[i])
	{
		return (0);
	}
	else
		return (-1);

}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d\n", ft_strcmp("hola", "hola"));
	printf("%d\n", ft_strcmp("hola", "hombre"));
	printf("%d\n", ft_strcmp("hola", " "));
	printf("----------\n");
	printf("%d\n", strcmp("hola", "hola"));
	printf("%d\n", strcmp("hola", "hombre"));
	printf("%d\n", strcmp("hola", " "));
}
*/