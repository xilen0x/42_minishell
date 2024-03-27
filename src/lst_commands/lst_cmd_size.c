/*cuenta el numero de nodos en una lista. Retorna un entero.*/
#include "minishell.h"

int	lst_cmd_size(t_cmd *lst)
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