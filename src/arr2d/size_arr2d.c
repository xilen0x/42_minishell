
#include "arr2d.h"

/*Counts the number of elements contained in a bi-dimensional array*/
size_t  size_arr2d(char **arr2d)
{
    size_t  size;

    size = 0;
    while(arr2d && arr2d[size])
        size++;
    return(size);
}