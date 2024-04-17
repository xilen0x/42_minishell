#ifndef QUOTE_REM_H
# define QUOTE_REM_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


int		tok_len(char *str);
char	*quote_removal(char *str, char **environ);
char 	*get_var_name(char *str);



/*----------UTILS DE LIBFT-----------*/
int		ft_isalnum(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


#endif