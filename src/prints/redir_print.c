#include "minishell.h"

/*===============ELIMINAR ANTES DE ENTREGA=============== */
/*----Imprime una lista t_redir----*/
void	redir_print(t_redir *lst)
{
	printf("     t_redir\n");
	if (!lst)
	{
		printf("            NULL\n");
		return;
	}
	while (lst)
	{
		printf("            %s\n", lst->filename);
		lst = lst->next;
	}
}