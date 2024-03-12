#ifndef UTILS_LIBFT_H
# define UTILS_LIBFT_H

# include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int     ft_strlcpy(char *dst, char *src, int dstsize);

#endif