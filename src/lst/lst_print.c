#include "minishell.h"

/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*------------------IMPRIME UNA LISTA------------------*/

//Recibe *simple porque NO se haran cambios en la lista
void	lst_print(t_lst *list)
{
	t_lst	*aux;

	aux = list;
	printf("===La_lista_contiene===\n");
	while (aux)
	{
		printf("value: >%s<\n", aux->value);
        printf("keyword: %s", aux->keyword);
        printf("----------\n");
		aux = aux->next;
	}
}