
#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

	if (lst == NULL || (*lst) == NULL)//BUENA PRACTICA
		return ;
	aux = (*lst);
	while (aux)
	{
		if (aux->command_and_arg)//BUENA PRACTICA
        	free_arr2d(aux->command_and_arg);
		if (aux->redir)
        	redir_free(&aux->redir);//redir_free(&(*lst)->redir);
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}