
//#include "minishell.h"
/*LA COMENTO PORQUE ESTA EN LIBFT   
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

size_t str_l_cpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t srcsize;

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

//int	ca_strcmp(char *s1, char *s2)
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (2);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (-1);
}
*/