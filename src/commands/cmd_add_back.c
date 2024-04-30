#include "minishell.h"

/*----Adds a node to the end of a list t_cmd----*/
void	cmd_add_back(t_cmd **lst,t_cmd *new)
{
	t_cmd	*aux;

	aux = NULL;
	if (*lst)
	{
		aux = cmd_last(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}