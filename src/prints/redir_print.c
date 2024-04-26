#include "minishell.h"

/*===============ELIMINAR ANTES DE ENTREGA=============== */
/*----Imprime una lista t_redir----*/
void	redir_print(t_redir *lst)
{
	printf("redirs\n");
	if (!lst)
	{
		printf("NULL");
		return;
	}
	while (lst)
	{
		printf("   %s (%i)\n", lst->filename, lst->redir_type);
		lst = lst->next;
	}
}