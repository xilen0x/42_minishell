#include "minishell.h"

/*Displays all elements contained in a bi-dimensional array*/
void  print_arr2d(char **arr2d)
{
    size_t  size;

    size = 0;
    while(arr2d && arr2d[size])
    {
        printf("%s\n", arr2d[size]);
        size++;
    }
    return ;
}