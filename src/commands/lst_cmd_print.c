#include "minishell.h"

/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*------------------IMPRIME UNA LISTA t_cmd------------------*/

//Recibe *simple porque NO se haran cambios en la lista
void	lst_cmd_print(t_cmd *list)
{
	t_cmd	*aux;
	int		i;

	aux = list;
	printf("=== %i NODOS t_cmd ===\n", lst_cmd_size(list));
	while (aux)
	{
		i = 0;
		printf("--**cmd_arg--\n");
		while (aux->cmd_arg[i] != NULL)
		{
			printf("%s$\n", aux->cmd_arg[i]);
			i++;
		}
		printf("--- %i NODOS t_redir ---\n", lst_cmd_size(list->fd_io));
		i = 0;
		while (aux->fd_io[i])
		{
			printf("%s$\n", aux->fd_io[i]->f_name);
        	printf("%u\n", aux->fd_io[i]->type);
//			printf("%s\n", *(cmd)->f_name);
        	printf("----------\n");
			i++;
		}
		aux = aux->next;
	}
	printf("\n");
}