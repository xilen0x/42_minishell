#include "minishell.h"

/*----Returns a pointer to the last node of a t_tok list---*/
t_tok	*tok_last(t_tok *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
