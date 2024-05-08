#include "minishell.h"

/*=========ELIMINAR ANTES DE ENTRGA SI SOLO SE USA EN print_tok=========*/
/*Counts the number of nodes of a t_lst list*/
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