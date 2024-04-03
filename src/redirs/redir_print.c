#include "minishell.h"

/*===============ELIMINAR ANTES DE ENTREGA=============== */
/*----Imprime una lista t_redir----*/
void	redir_print(t_redir *lst)
{
	printf("= t_redir list (%i) =\n", redir_size(lst));
	if (!lst)
	{
		printf("NULL");
		return;
	}
	while (lst)
	{
        printf("----\n");
		printf("%s\n", lst->filename);
        printf("%i\n", lst->redir_type);
		lst = lst->next;
	}
}
