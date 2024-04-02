#include "minishell.h"

/*===============ELIMINAR ANTES DE ENTREGA=============== */
/*----Imprime una lista t_redir----*/
void	redir_print(t_redir *lst)
{
//	t_redir	*aux;

//	aux = lst;
//	printf("--- %i NODOS t_redir ---\n", redir_size(lst));
	printf("= t_redir list =\n");
	while (lst)
	{
		printf("%s\n", lst->filename);
        printf("%i\n", lst->redir_type);
        printf("----\n");
		lst = lst->next;
	}
//	printf("\n");
}