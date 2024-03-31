
#include "minishell.h"

/*---Frees and clears a 't_cmd' list---*/
void	cmd_free(t_cmd **lst)
{
	t_cmd	*aux;

	aux = (*lst);
	while (aux)
	{
        free_arr2d(aux->command_and_arg);
        redir_free((*lst)->redir);
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
/*NO ESTOY SEGURO SI ESTA FUNCION ES CORRECTA*/