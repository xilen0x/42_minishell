/*Counts the number of nodes of a t_lst list*/
#include "minishell.h"

int	tok_size(t_tok *lst)
{
	int	size;

	size = 0;
	if (lst != 0)
	{
		while (lst != 0)
		{
			lst = lst->next;
			size++;
		}
	}
	return (size);
}