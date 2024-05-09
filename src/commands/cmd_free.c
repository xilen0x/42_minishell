
#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

	if (lst == NULL || (*lst) == NULL)
		return ;
	aux = (*lst);
	while (aux != NULL)
	{
		if (aux->commands != NULL)
        	free_arr2d(aux->commands);
		if (aux->redir != NULL)
        	redir_free(&aux->redir);
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
