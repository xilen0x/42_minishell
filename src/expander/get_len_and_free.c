#include "minishell.h"

/*Gets the length of a *str, frees it, and sets it to NULL*/
size_t	get_len_and_free(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	free(str);
	str = NULL;
	return (len);
}