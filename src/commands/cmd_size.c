#include "minishell.h"

/*Returns the node number of a 't_cmd' list */
int	cmd_size(t_cmd *lst)
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
