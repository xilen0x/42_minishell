
#include "minishell.h"

/*----ADDS A NODE TO THE END OF A LIST. NOTHING IS RETURNED---*/
void	lst_add_back(t_lst **lst,t_lst *new)
{
	t_lst	*aux;

	if (*lst)
	{
		aux = lst_last(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
