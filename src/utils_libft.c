
#include "minishell.h"

//COPIADAS DE LIBFT

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dup = (char *) malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	return (dup);
}

int ft_strlcpy(char *dst, char *src, int dstsize)
{
	int i;
	int srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}