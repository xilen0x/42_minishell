
#include "../include/minishell.h"

/*Makes a new copy allocated and NULL terminated of **arr_2d adding *str at the end. The old **arr_2d is freed.*/
/*char    **add_one_2d_arr(char **arr_2d, char *str)
{
    char    **new_arr_2d;
    size_t  size;
    int     i;

    size = size_2d_arr(arr_2d);
    new_arr_2d = (char **)malloc((size + 2) * sizeof(char *));
    while (i < size)
    {
        new_arr_2d[i] = ft_strdup(arr_2d[i]);
        i++;
    }
    new_arr_2d[i] = ft_strdup(str);
    new_arr_2d[i + 1] = NULL;
    free_2d_arr(arr_2d);
    return (new_arr_2d);
}*/