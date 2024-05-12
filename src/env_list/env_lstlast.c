#include "minishell.h"

//Returns the last node of a 't_env' list
t_env	*lstlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}