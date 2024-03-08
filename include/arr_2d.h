
#ifndef ARR_2D_H
# define ARR_2D_H

# include "minishell.h"

char	**dup_2d_arr(char **arr_2d);
size_t  size_2d_arr(char **arr_2d);    
void    free_2d_arr(char **arr_2d);
char    **add_one_2d_arr(char **arr_2d, char *str);
char    **rm_one_2d_arr(char **arr_2d, char *str);//creo es mejor/mas facil remover por nombre de variable y no por indice
char    **set_2d_arr(char **arr, char *str, char *new_str);//creo mejor/mas facil settearla por nombre y no por indice

#endif