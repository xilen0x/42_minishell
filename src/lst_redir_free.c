#include "minishell.h"

/*------LIBERA TODA LA LISTA t_redir Y PONE LOS VALORES A NULL------*/
void	lst_free(t_redir **lst)
{
	t_lst	*aux;

	aux = (*lst);
	while (aux)
	{
		aux->f_name = NULL;
		aux->key = NULL;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}