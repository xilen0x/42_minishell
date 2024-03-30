#include "minishell.h"

/*----Imprime lista t_cmd---ELIMINAR ANTES DE ENTREGA----*/

void	cmd_print(t_cmd *list)
{
	t_cmd	*aux;
	int		i;

	aux = list;
	printf("=== %i NODOS t_cmd ===\n", cmd_size(list));
	while (aux)
	{
		i = 0;
		printf("--**command--\n");
		while (aux->command_and_arguments[i] != NULL)
		{
			printf("%s$\n", aux->command_and_arguments[i]);
			i++;
		}
		printf("--- %i NODOS t_redir ---\n", cmd_size(list->io_redirect_list));
		i = 0;
		while (aux->io_redirect_list[i])
		{
			printf("%s$\n", aux->io_redirect_list[i]->filename);
        	printf("%u\n", aux->io_redirect_list[i]->type);
//			printf("%s\n", *(cmd)->filename);
        	printf("----------\n");
			i++;
		}
		aux = aux->next;
	}
	printf("\n");
}