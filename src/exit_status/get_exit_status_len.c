#include "minishell.h"

unsigned int	get_exit_status_len(t_exe *exe)
{
	unsigned int	len;
	char			*val;

	len = 0;
	val = get_exit_status_val(exe);//retorna un char * mallocado
	len = ft_strlen(val);
	free(val);
	return (len);
}