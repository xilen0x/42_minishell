
#include "minishell.h"

/*----RETURNS A POINTER TO THE LAST NODE OF A LIST----*/
t_lst	*ft_lstlast2(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
