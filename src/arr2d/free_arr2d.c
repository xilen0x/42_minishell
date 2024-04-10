
#include "minishell.h"

/*Frees all elements of an **arr2d included the main pointer as well.*/
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
	// printf("free_arr2d 4\n");
	arr2d = NULL;
}
