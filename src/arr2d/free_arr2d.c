
#include "minishell.h"

/*Frees all elements of an **arr2d included the main pointer as well.*/

/* this function has been replaced by the next one
void    free_arr2d(char **arr2d)
{
    char    **tmp;

    tmp = arr2d;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(arr2d);
}*/

void	free_arr2d(char **array_strings)
{
	size_t	i;

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
	}
}