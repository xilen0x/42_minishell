#include "minishell.h"

/*----Returns a pointer to the last node of a t_cmd list---*/
t_cmd	*cmd_last(t_cmd *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}