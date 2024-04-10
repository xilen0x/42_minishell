
#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

	aux = (*lst);
	while (aux)
	{
		if (aux->command_and_arg)
		{
			free_arr2d(aux->command_and_arg);
			aux->command_and_arg = NULL;
		}
		redir_free(&(*lst)->redir);
		if (aux->next)
		{
			(*lst) = aux->next;
			free(aux);
			aux = (*lst);
		}
		else
			aux = NULL;

	}
	(*lst) = NULL;
}
