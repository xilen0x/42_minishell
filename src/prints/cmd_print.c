#include "minishell.h"

/*----Imprime lista t_cmd---ELIMINAR ANTES DE ENTREGA----*/

void	cmd_print(t_cmd *lst)
{
	int	i;
	int	j;

	j = 0;
	while (lst != NULL)
	{
		i = 0;
		printf("=== command %i ===\n", j);
		while (lst->command_and_arg[i] != NULL)
			{
				printf("   %s\n", lst->command_and_arg[i]);
				i++;
			}
		printf("\n");
		if (lst->redir != NULL)
			redir_print(lst->redir);
		else
			printf("redirs = NULL\n");

		printf("\n");
		j++;
		lst = lst->next;
	}
	printf("\n");
}