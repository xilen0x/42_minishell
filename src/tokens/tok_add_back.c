#include "minishell.h"

/*----Adds a node to the end of a list t_tok----*/
void	tok_add_back(t_tok **lst,t_tok *new)
{
	t_tok	*aux;

	if (*lst)
	{
		aux = tok_last(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
