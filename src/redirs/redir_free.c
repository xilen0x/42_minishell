#include "minishell.h"

/*----Libera y limpia una lista t_redir----*/
void	redir_free(t_redir **lst)
{
	t_redir	*aux;

//	if (lst == NULL || (*lst) == NULL)//BUENA PRACTICA
//		return ;
	aux = (*lst);
	while (aux)
	{
		if (aux->filename != NULL)//BUENA PRACTICA
		{
			free(aux->filename);
			aux->filename = NULL;//BUENA PRACTICA
		}
		if (aux->redir_type != 0)
			aux->redir_type = 0;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}