#include "minishell.h"

/*----Imprime una lista t_tok----*/
void	print_tok(t_tok *lst)
{
	printf("\n=== %i tokens ===\n", tok_size(lst));
	while (lst)
	{
		printf("%s (%u)\n", lst->str, lst->type);
		lst = lst->next;
	}
	printf("\n");
}
