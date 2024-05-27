#include "minishell.h"

/* Deletes a 't_env' list and frees all its nodes */
void	cleaner_envlist(t_env **lst)
{
	t_env	*aux;

	aux = (*lst);
	while (aux)
	{
		free(aux->key);
		aux->key = NULL;
		free(aux->val);
		aux->val = NULL;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
