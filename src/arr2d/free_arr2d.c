
#include "minishell.h"

/*Frees all elements of an **arr2d included the main pointer as well.*/

/* this function has been replaced by the next one
void    free_arr2d(char **arr2d)
{
    // char    **tmp;

    // tmp = arr2d;
	// printf("free_arr2d 0 (%p)\n", arr2d);
	// printf("free_arr2d 1 (%s)\n", *tmp);
    // while (tmp && *tmp)

	// int x = 0;
	// while(arr2d[x])
    // {
		// printf("free_arr2d 2 (%s)\n", *tmp);
        // free(*tmp);
        // tmp++;
		// free(arr2d[x]);
		// x++;
		// arr2d++;
    // }
	// printf("free_arr2d 3\n");
    free(arr2d);
}*/

void	free_arr2d(char **array_strings)
{
	size_t	i;

	if (array_strings == NULL || array_strings[0] == NULL)
		return ;
	i = 0;
	if (array_strings)
	{
		while (array_strings[i])
		{
			free(array_strings[i]);
			array_strings[i] = NULL;
			i++;
		}
		free(array_strings);
		array_strings = NULL;
	}
}
