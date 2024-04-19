#include "minishell.h"

/*===============ELIMINAR ESTE FILE ANTES DE ENTREGA=============== */

/*----Imprime una lista t_tok----*/
void	tok_print(t_tok *lst)
{
	printf("\n=== t_tok list (%i) ===\n", tok_size(lst));
	while (lst)
	{
		printf("----\n");
		printf("%s\n", lst->str);
		printf("%u\n", lst->type);
		lst = lst->next;
	}
	printf("\n");
}
