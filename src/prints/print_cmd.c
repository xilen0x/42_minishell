#include "minishell.h"

/*----Imprime lista t_cmd---ELIMINAR ANTES DE ENTREGA----*/
void	print_cmd(t_cmd *lst)
{
	int	i;

	while (lst != NULL)
	{
		i = 0;
		printf("-----------------------\n");
		printf("t_cmd\n");
		while (lst->command_and_arg[i] != NULL)
<<<<<<< HEAD
			{
				printf("     <%s>\n", lst->command_and_arg[i]);
				i++;
			}
=======
		{
			printf("     %s\n", lst->command_and_arg[i]);
			i++;
		}
>>>>>>> origin/carlos
		printf("\n");
		if (lst->redir != NULL)
			print_redir(lst->redir);
		else
			printf("     t_redir = NULL\n");
		lst = lst->next;
	}
	printf("-----------------------\n");
}
