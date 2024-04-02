#include "minishell.h"
/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*----Imprime una lista t_tok----*/
void	tok_print(t_tok *lst)
{
	t_tok	*aux;//creo que no haria falta este auxiliar, porque entra un puntero simple

	aux = lst;
	printf("\n=== %i nodos t_tok ===\n", tok_size(lst));
	while (aux)
	{
		printf("%s$\n", aux->str);
        printf("%u\n", aux->type);
        printf("----------\n");
		aux = aux->next;
	}
	printf("\n");
}