#include "minishell.h"

/*===============ELIMINAR ANTES DE ENTREGA=============== */
/*----Imprime una lista t_redir----*/
void	redir_print(t_redir *lst)
{
	t_redir	*aux;

	aux = lst;
	printf("--- %i NODOS t_redir ---\n", redir_size(lst));
	while (aux)
	{
		printf("%s$\n", aux->filename);
        //printf("%i\n", aux->red_io);
        printf("----------\n");
		aux = aux->next;
	}
	printf("\n");
}