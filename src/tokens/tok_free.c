#include "minishell.h"

/*-----Frees and clears a 't_tok' list-----*/
/*
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
}*/
void	tok_free(t_tok **lst)
{
	t_tok	*aux;
	t_tok	*next_node;

	if (lst == NULL || *lst == NULL)
		return;
	aux = (*lst);
	while (aux != NULL)
	{
		next_node = aux->next;
		if (aux->str != NULL)
			free (aux->str);
		free(aux);
		aux = next_node;
	}
	(*lst) = NULL;
//	free(lst);//added in the last moment
}