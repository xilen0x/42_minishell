/*cuenta el numero de nodos en una lista. Retorna un entero.*/
#include "minishell.h"

int	jc_lstsize(t_lst *lst)
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