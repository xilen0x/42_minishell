#include "minishell.h"

/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*------------------IMPRIME UNA LISTA t_lst------------------*/

//Recibe *simple porque NO se haran cambios en la lista
void	lst_print(t_lst *list)
{
	t_lst	*aux;

	aux = list;
	printf("=== %i NODOS t_lst ===\n", lst_size(list));
	while (aux)
	{
		printf("%s$\n", aux->val);
        printf("%u\n", aux->key);
        printf("----------\n");
		aux = aux->next;
	}
	printf("\n");
}