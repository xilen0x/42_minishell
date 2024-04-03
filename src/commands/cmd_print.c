#include "minishell.h"

/*----Imprime lista t_cmd---ELIMINAR ANTES DE ENTREGA----*/

void	cmd_print(t_cmd *lst)
{
	int		i;

	printf("=== t_cmd list (%i) ===\n", cmd_size(lst));
	while (lst != NULL)
	{
			i = 0;
			while (lst->command_and_arg[i] != NULL)
			{
				printf("	%s\n", lst->command_and_arg[i]);
				i++;
			}
			printf("\n");
			if (lst->redir != NULL)
				redir_print(lst->redir);
			else
				printf("t_dir = NULL\n");
			printf("======================\n");
			lst = lst->next;
	}
	printf("\n");
}