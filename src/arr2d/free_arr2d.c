
#include "arr2d.h"

/*Frees all elements of an **arr2d included the main pointer as well.*/
void    free_arr2d(char **arr2d)
{
    char    **tmp;

    tmp = arr2d;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(tmp);
}