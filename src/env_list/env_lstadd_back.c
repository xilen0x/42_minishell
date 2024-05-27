#include "minishell.h"

/*--Adds a node to the end of a 't_env' list---*/
void	lstadd_back(t_env **lst, t_env *new)
{
	t_env	*aux;

	if (*lst)
	{
		aux = lstlast(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
