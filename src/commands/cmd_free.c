
#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

//	if (*lst != NULL && lst != NULL)
	aux = (*lst);
	while (aux)
	{
        free_arr2d(aux->command_and_arg);
        redir_free(&(*lst)->redir);
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}