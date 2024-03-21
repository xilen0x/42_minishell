/*-----------FREE THE ALLOCATED MEM IN THE LIST------------*/

#include "minishell.h"

void	jc_lstclear(t_lst **lst)
{
	t_lst	*aux;

	aux = (*lst);
	while (aux)
	{
		aux->val = NULL;//añadido para que se limpie totalmemte. No se si hace falta ???
		aux->key = NULL_KEY;//añadido para que se limpie totalmemte
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}