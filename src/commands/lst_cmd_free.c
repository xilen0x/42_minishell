
#include "minishell.h"

void	lst_free(t_cmd **lst)
{
	t_cmd	*aux;

	aux = (*lst);
	while (aux)
	{
        free_arr2d(aux->cmd_arg);//libera y limpia toda la matriz
        liberar y borrar lista 

		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}