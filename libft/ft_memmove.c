/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:08 by castorga          #+#    #+#             */
/*   Updated: 2023/06/14 15:04:35 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies from one part of memory to another, preventing possible overlaps*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (pdst > psrc)
	{
		while (len != 0)
		{
			len--;
			pdst[len] = psrc[len];
		}
	}
	else
		ft_memcpy(pdst, psrc, len);
	return (dst);
}

/*
int main (void)
{
	//char src[] = "welcome!";
	// printf("\n---------memmove-------------*\n");
	//char dst[] = "  ";
	//printf("%s\n", (char *)memmove(dst, src, 3));

	char src[] = "welcome";
	printf("\n---------ft_memmove----------*\n");
	char dst2[] = "  ";
	printf("%s", (char *)ft_memmove(dst2, src, 3));

	return 0;
}
*/
