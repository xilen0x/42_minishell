#ifndef LST_H
# define LST_H

# include "minishell.h"
# include <stdlib.h>//quizas se puede omitir porque esta en minishell.h

t_lst	*lstnew_node(char *value, int keyword);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	lst_print(t_lst *list);//ELIMINAR ANTES DE ENTREGA
#endif