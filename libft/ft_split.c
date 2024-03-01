/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/08 10:08:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Reserva, utilizando malloc, un array de strings resultante de separar la
 * string 's' en substrings utilizando el caracter 'c' como delimitador. El
 * array se termina/cierra con un puntero NULL.*/

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#include "libft.h"
/*
void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t          i;
    unsigned char   *s;
    unsigned char   *d;

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

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strdup(const char *s1)
{
    char    *dup;
    size_t  len;

    len = ft_strlen(s1) + 1;
    dup = (char *) malloc(len * sizeof(char));
    if (!dup)
        return (NULL);
    ft_memcpy(dup, s1, len);
    return (dup);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *sub;
    unsigned int    i;
    unsigned int    s_len;

    i = 0;
    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start > s_len)
        return (ft_strdup(""));
    if (ft_strlen(&s[start]) < len)
        len = ft_strlen(&s[start]);
    sub = (char *) malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    while (s[start + i] && i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

void    ft_bzero(void *s, size_t n)
{
    char    *a;
    int     i;

    i = 0;
    a = s;
    while (n > 0)
    {
        a[i] = 0;
        i++;
        n--;
    }
}

void    *ft_calloc(size_t count, size_t size)
{
    void    *array;

    array = malloc(count * size);
    if (!array)
        return (NULL);
    ft_bzero(array, (count * size));
    return (array);
}*/

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	**ft_free(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		num;
	int		start;

	i = -1;
	num = 0;
	split = (char **)ft_calloc((ft_counter(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (num < ft_counter(s, c) && i++ >= -1)
	{
		if (s[i] != c && s[i])
		{
			start = i;
			num++;
			while (s[i] != c && s[i] != '\0')
				i++;
			split[num - 1] = ft_substr(s, (unsigned int)start, i - start);
			if (!split[num - 1])
				return (ft_free(split, num - 2));
		}
	}
	return (split);
}
/*
int	main(void)
{
	char	s[] = "       sssss             q      ";
	char	c = ' ';
	char	**split;
	int		i = 0;

	split = ft_split(s, c);
	printf("split=%p\n", *split);
	while (split[i])
	{
		printf("%i   >%s<\n", i, split[i]);
		i++;
	}
	ft_free(split, i);
	return (0);
}*/
