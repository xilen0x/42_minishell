#include "minishell.h"

void	malloc_s_pointer_protect(void *name)
{
	if (!name)
	{
		printf("Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
}

void	malloc_d_pointer_protect(char **name)
{
	if (!name)
	{
		printf("Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
}