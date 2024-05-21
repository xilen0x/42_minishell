#include "minishell.h"

/*funcion que busca un caracter en un string y retorna 1 si lo encuentra*/
int	ca_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char) c;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
