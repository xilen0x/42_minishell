/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:25:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 09:59:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function computes the length of the string s. Returns the number of 
 * characters that precede the terminating NUL character.*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
