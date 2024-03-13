
#include "minishell.h"

/*----ADDS A NODE TO THE END OF A LIST. NOTHING IS RETURNED---*/
void	ft_lstadd_back(t_lst **lst,t_lst *new)
{
	t_lst	*aux;

	if (*lst)
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}