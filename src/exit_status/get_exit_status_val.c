#include "minishell.h"

char	*get_exit_status_val(unsigned int exit_status)
{
	char	*result;

	result = itoa(exit_status);
	if (!result)
		exit (EXIT_FAILURE);
	return (result);//OJO: itoa retorna un char* mallocado
}