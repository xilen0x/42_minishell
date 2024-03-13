
#ifndef ARR2D_H
# define ARR2D_H

# include <stdlib.h>

char	**dup_arr2d(char **arr2d);
size_t  size_arr2d(char **arr2d);
void    free_arr2d(char **arr2d);
char    **add_one_arr2d(char **arr2d, char *new);
char    **rm_one_arr2d(char **arr2d, int index);
char    **set_one_arr2d(char **arr2d, char *new_str, int index);//esta pendiente de hacer (si hace falta)


char    *get_value_arr(char **arr, char *name);//pendiente de hacer(si hace falta)
// pendiente de hacer una funcion que comprueba si existe o no una variable env (puede retornar TRUE o FALSE, si existe podre reemplazarla, removerla o liberarla, si no existe podre añadirla)

#endif