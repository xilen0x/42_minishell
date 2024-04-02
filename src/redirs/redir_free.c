#include "minishell.h"

/*----Libera y limpia una lista t_redir----*/
void	redir_free(t_redir **lst)
{
	t_redir	*aux;

//	if (*lst != NULL && lst != NULL)
	aux = (*lst);
	while (aux)
	{
		aux->filename = NULL;
		aux->redir_type = NULL_REDIR;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}