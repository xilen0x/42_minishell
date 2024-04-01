#include "minishell.h"

/*----Imprime lista t_cmd---ELIMINAR ANTES DE ENTREGA----*/

void	cmd_print(t_cmd *list)
{
	t_cmd	*aux;//CREO NO HARIA FALTA EL AUX
	int		i;

	aux = list;
	printf("=== %i NODOS t_cmd ===\n", cmd_size(list));
	while (aux)
	{
		i = 0;
		printf("-- char **command_and_arg --\n");
		while (aux->command_and_arg[i] != NULL)
		{
			printf("%s$\n", aux->command_and_arg[i]);
			i++;
		}
//		printf("--- %i NODOS t_redir ---\n", redir_size(list->redir));
//		i = 0;
		redir_print(aux->redir);//printa la lista t_redir
/*		while (aux->redir_type[i])
		{
			printf("%s$\n", aux->redir_type[i]->filename);
        	printf("%u\n", aux->redir_type[i]->type);
//			printf("%s\n", *(cmd)->filename);
        	printf("----------\n");
			i++;
		}*/
		aux = aux->next;
	}
	printf("\n");
}