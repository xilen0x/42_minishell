
#include "include/minishell.h"

void    free_array_2d(char **array_2d)
{
    char    **tmp;

    tmp = array_2d;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(tmp);
}