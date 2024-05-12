#include "minishell.h"

//extern int	get_signal;

char	*get_exit_status_val(void)
{
	char	*result;

	result = ft_itoa(get_signal);
	if (!result)
		exit (EXIT_FAILURE);
	return (result);//retorna un char* mallocado
}