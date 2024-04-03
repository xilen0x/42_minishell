#include "minishell.h"

/*----Adds a node to the end of a list t_redir----*/
void	redir_add_back(t_redir **lst,t_redir *new)
{
	t_redir	*aux;

	if (*lst)
	{
		aux = redir_last(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}