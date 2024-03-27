#include "minishell.h"

/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*------------------IMPRIME UNA LISTA t_cmd------------------*/

//Recibe *simple porque NO se haran cambios en la lista
void	lst_cmd_print(t_cmd *list)
{
	t_cmd	*aux;
	int		i;

	aux = list;
	i = 0;
	printf("=== %i NODOS t_cmd ===\n", lst_cmd_size(list));
	while (aux)
	{
		printf("--**cmd_arg--\n");
		while (aux->cmd_arg[i] != NULL)
		{
			printf("%s$", aux->cmd_arg[i]);
			i++;
		}
		printf("-------------\n");
        printf("%u\n", aux->key);



        printf("----------\n");
		aux = aux->next;
	}
	printf("\n");
}