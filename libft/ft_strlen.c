/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:14:00 by castorga          #+#    #+#             */
/*   Updated: 2023/05/09 13:14:03 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *arg = "welcome";

	printf("\n---strlen----");
	printf("\nstring lenght: %d", (unsigned)strlen(arg));
	printf("\n---ft_strlen----");
	printf("\nstring lenght: %d", (unsigned)ft_strlen(arg));

	return (0);
}*/