
#include "minishell.h"

/*------RETORNA UN NUEVO NODO INICIALIZADO CON LOS ARGUMENTOS---------*/
t_lst	*lstnew_node(char *value, int keyword)
{
	t_lst	*node;

	 node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->value = value;
	node->keyword = keyword;
    node->next = NULL;
	return (node);
}