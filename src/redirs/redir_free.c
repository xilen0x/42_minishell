#include "minishell.h"

/*----Libera y limpia una lista t_redir----*/
void	redir_free(t_redir **lst)
{
	t_tok	*aux;

	aux = (*lst);
	while (aux)
	{
		aux->filename = NULL;
		aux->key = NULL;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}