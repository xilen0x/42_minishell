/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:49:08 by castorga          #+#    #+#             */
/*   Updated: 2023/06/14 13:06:26 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies from one part of memory to another, ignoring possible overlaps */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*psrc;
	char			*pdst;

	if (dst == NULL && src == NULL)
		return (NULL);
	psrc = (char *)src;
	pdst = (char *)dst;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}

/*

int main ()
{
	printf("\n---------memcpy-------------*\n");
	char src[] = "every programmer should know memcpy!";
	char dst[] = "**********";
	printf("%s\n", (char *)memcpy(dst + 4, src, 5));

	printf("\n---------ft_memcpy----------*\n");
	char src2[] = "every programmer should know memcpy!";
	char dst2[] = "**********";
	printf("%s\n", (char *)ft_memcpy(dst2 + 4, src2, 5));
	return 0;
}
*/
