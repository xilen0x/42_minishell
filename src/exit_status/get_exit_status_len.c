#include "minishell.h"

unsigned int	get_exit_status_len(unsigned int *exit_status)
{
	unsigned int	len;
	char			*val;

	len = 0;
	val = get_exit_status_val(exit_status);//ojo: retorna un char * mallocado
	len = ft_strlen(val);
	free(val);
	return (len);
}