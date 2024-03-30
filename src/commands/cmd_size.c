/*cuenta el numero de nodos en una lista t_cmd*/
#include "minishell.h"

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