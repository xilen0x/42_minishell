#include "minishell.h"

char	*get_exit_status_val(t_exe *exe)
{
	char	*result;

	result = ft_itoa(exe->exit_stat);
	if (!result)
		exit (EXIT_FAILURE);
	return (result);//retorna un char* mallocado
}