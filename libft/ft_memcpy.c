/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:03:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/07/06 12:20:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*The memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.
	 Returns the original value of dst.*/

//#include<string.h>
//#include<stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
int	main(void)
{
	char	src[] = "ho\0la mundo";
	char	dst[] = "xxxxxxxxxx";
	char	src1[] = "ho\0la mundo";
	char	dst1[] = "xxxxxxxxxx";
	char	src2[] = "";
	char	dst2[] = "";
	char	src3[] = "";
	char	dst3[] = "";
	size_t	n = 2;
	printf("ft_memcpy>%s<\n", (unsigned char *)ft_memcpy(dst, src, n));
	printf("  _memcpy>%s<\n", (unsigned char *)memcpy(dst1, src1, n));
	printf("ft_memcpy>%s<\n", (unsigned char *)ft_memcpy(dst2, src2, n));
	printf("  _memcpy>%s<\n", (unsigned char *)memcpy(dst3, src3, n));
	return (0);
}*/
