#include "minishell.h"

/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*------------------IMPRIME UNA LISTA------------------*/

//Recibe *simple porque NO se haran cambios en la lista
void	lst_print(t_lst *list)
{
	t_lst	*aux;

	aux = list;
	printf("=== %i NODOS ===\n", jc_lstsize(list));
	while (aux)
	{
		printf("%s$\n", aux->val);
        printf("%u\n", aux->key);
        printf("----------\n");
		aux = aux->next;
	}
	printf("\n");
}