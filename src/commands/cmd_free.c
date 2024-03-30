
#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

	aux = (*lst);
	while (aux)
	{
        free_arr2d(aux->command_and_arguments);//libera y limpia toda la matriz
        liberar y borrar lista 

		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}