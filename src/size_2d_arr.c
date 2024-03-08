
#include "../include/minishell.h"

/*Counts the number of elements contained in a bi-dimensional array*/
size_t  size_2d_arr(char **arr_2d)
{
    size_t  size;

    size = 0;
    while(arr_2d && arr_2d[size])
        size++;
    return(size);
}