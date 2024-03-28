/*-----------FREE THE ALLOCATED MEM IN THE LIST------------*/

#include "minishell.h"
/*------LIBERA TODA LA LISTA Y PONE LOS VALORES A NULL------*/
void	lst_free(t_lst **lst)
{
	t_lst	*aux;

	aux = (*lst);
	while (aux)
	{
		aux->val = NULL;
		aux->key = NULL;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}