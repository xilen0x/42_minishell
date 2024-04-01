#include "minishell.h"

/*----Libera y limpia una lista t_redir----*/
void	redir_free(t_redir **lst)
{
	t_redir	*aux;

	aux = (*lst);
	while (aux)
	{
		aux->filename = NULL;
		aux->red_io = NULL_REDIR;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}