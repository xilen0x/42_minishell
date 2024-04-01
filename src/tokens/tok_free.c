#include "minishell.h"

/*-----Frees and clears a 't_tok' list-----*/
void	tok_free(t_tok **lst)
{
	t_tok	*aux;

	aux = (*lst);
	while (aux)
	{
		aux->str = NULL;
		aux->type = NULL_TYPE;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}