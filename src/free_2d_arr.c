
#include "../include/minishell.h"

/*Frees all elements of  **arr_2d included the main pointer as well.*/
void    free_2d_arr(char **arr_2d)
{
    char    **tmp;

    tmp = arr_2d;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(tmp);
}