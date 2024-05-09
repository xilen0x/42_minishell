#include "minishell.h"

/*----Imprime lista t_cmd para entrega a executor---ELIMINAR ANTES DE ENTREGA----*/
void	print_cmd_para_executor(t_cmd *lst)
{
	int	i;
	while (lst != NULL)
	{
		i = 0;
		printf("-----------------------\n");
		printf("t_cmd para executor\n");
		printf("     <");
		while (lst->commands[i] != NULL)
			{
				printf("%s", lst->commands[i]);
				i++;
			}
		printf(">\n");
		if (lst->redir != NULL)
			print_redir(lst->redir);
		else
			printf("     t_redir = NULL\n");
		lst = lst->next;
	}
	printf("-----------------------\n");
}