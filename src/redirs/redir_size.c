#include "minishell.h"

/*=========ELIMINAR ANTES DE ENTRGA SI SOLO SE USA EN print_redir=========*/
/*Counts the number of nodes of a t_redir list*/
int	redir_size(t_redir *lst)
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
