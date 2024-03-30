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
		while (aux->command[i] != NULL)
		{
			printf("%s$\n", aux->command[i]);
			i++;
		}
		printf("--- %i NODOS t_redir ---\n", cmd_size(list->file_io));
		i = 0;
		while (aux->file_io[i])
		{
			printf("%s$\n", aux->file_io[i]->filename);
        	printf("%u\n", aux->file_io[i]->type);
//			printf("%s\n", *(cmd)->filename);
        	printf("----------\n");
			i++;
		}
		aux = aux->next;
	}
	printf("\n");
}