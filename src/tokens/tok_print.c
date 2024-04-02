#include "minishell.h"
/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*----Imprime una lista t_tok----*/
void	tok_print(t_tok *lst)
{
//	t_tok	*aux;//creo que no haria falta este auxiliar, porque entra un puntero simple

//	aux = lst;
//	printf("\n=== %i nodos t_tok ===\n", tok_size(lst));
	printf("\n=== t_tok list ===\n");
	while (lst)
	{
		printf("%s\n", lst->str);
        printf("%u\n", lst->type);
        printf("----\n");
		lst = lst->next;
	}
	printf("\n");
}