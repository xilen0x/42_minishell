#include "minishell.h"

// Allocates 'size' bytes of memory and returns a pointer to it.
// Exits properly if memory allocation fails.
void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		printf("Error: memory allocation failure\n");
		exit (EXIT_FAILURE);
	}
	return (ptr);
}
