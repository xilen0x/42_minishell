
#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

//	if (lst == NULL || (*lst) == NULL)//BUENA PRACTICA
//		return ;
	aux = (*lst);
	while (aux != NULL)
	{
		if (aux->command_and_arg != NULL)
        	free_arr2d(aux->command_and_arg);
		if (aux->redir != NULL)
        	redir_free(&aux->redir);//EL & ME PROVOCA MUCHAS DUDAS
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}