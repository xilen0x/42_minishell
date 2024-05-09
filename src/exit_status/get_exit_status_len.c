#include "minishell.h"

unsigned int	get_exit_status_len(void)
{
	unsigned int	len;
	char			*val;

	len = 0;
	val = get_exit_status_val(get_signal);//retorna un char * mallocado de la variable global que contiene el exit_status
	len = ft_strlen(val);
	free(val);
	return (len);
}