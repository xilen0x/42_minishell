
#include "minishell.h"

/*   Retorna una copia mallocada del array 2d habiendo eliminado el elemento index. Libera el array original */
//argumentos: el array 2d y el indice del elemento a eliminar. Si hay un fallo en la memoria retorna NULL
char    **rm_one_arr2d(char **arr2d, int index)
{
    char    **new_arr2d;
    char    **tmp_arr2d;
    size_t  size;
    int     i;

    i = 0;
    tmp_arr2d = arr2d;
    size = size_arr2d(arr2d);
    new_arr2d = (char **)malloc(size * sizeof(char *));
    if (!new_arr2d)
        return (NULL);
    while (i < index)
    {
        new_arr2d[i] = ft_strdup(tmp_arr2d[i]);
        i++;
    }
    while (tmp_arr2d[i + 1])
    {
        new_arr2d[i] = ft_strdup(tmp_arr2d[i + 1]);
        i++;
    }
    new_arr2d[i] = NULL;
    free_arr2d(arr2d);
    return (new_arr2d);
}