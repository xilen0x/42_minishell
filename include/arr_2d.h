
#ifndef ARR_2D_H
# define ARR_2D_H

# include "minishell.h"

char	**dup_2d_arr(char **arr_2d);
size_t  size_2d_arr(char **arr_2d);    
void    free_2d_arr(char **arr_2d);
//void    free_one_2d_arr(char **arr_2d, char *str);//NO HARIA FALTA SI YA ESTA ABAJO
char    **add_one_2d_arr(char **arr_2d, char *str, ????);//supongo debere rehacer todo el malloc y volver a rellenar todo
char    **rm_one_2d_arr(char **arr_2d, char *str, ???);//hacer un remove + free
char    **set_2d_arr(char **arr, char *str, int pos/index ???);//no tengo claro cual seria ultimo arg

//PONER ABOVE UNA DEFINICION COMENTADA A CADA FUNCION 
#endif