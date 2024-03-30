#include "minishell.h"

/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*------------------IMPRIME UNA LISTA t_tok------------------*/

//Recibe *simple porque NO hara cambios en la lista
void	tok_print(t_tok *lst)
{
	t_tok	*aux;

	aux = lst;
	printf("=== %i NODOS t_tok ===\n", tok_size(lst));
	while (aux)
	{
		printf("%s$\n", aux->str);
        printf("%u\n", aux->type);
        printf("----------\n");
		aux = aux->next;
	}
	printf("\n");
}