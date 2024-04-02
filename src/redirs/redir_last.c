#include "minishell.h"

/*----Returns a pointer to the last node of a t_redir list---*/
t_redir	*redir_last(t_redir *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}