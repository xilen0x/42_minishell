#include "minishell.h"

/*----Imprime lista t_cmd---ELIMINAR ANTES DE ENTREGA----*/

void	cmd_print(t_cmd *list)
{//	t_cmd	*aux;//CREO NO HARIA FALTA EL AUX
	int		i;

//	aux = list;
//	printf("=== %i NODOS t_cmd ===\n", cmd_size(list));
	printf("=== t_cmd list ===\n");
	while (list)
	{
//		if (list)
//		{
			i = 0;
			printf("-command_and_arg-\n");
			while (list->command_and_arg[i] != NULL)
			{
				printf("	%s\n", list->command_and_arg[i]);
				i++;
			}
			printf("\n");
//			printf("--- %i NODOS t_redir ---\n", redir_size(list->redir));
//			i = 0;
			redir_print(list->redir);//printa la lista t_redir
			printf("======\n");
//		}
		list = list->next;
	}
	printf("\n");
}