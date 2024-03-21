
#include "minishell.h"

/*------RETORNA UN NUEVO NODO INICIALIZADO CON LOS ARGUMENTOS---------*/
t_lst	*lstnew_node(char *value, int key)
{
	t_lst	*node;

	 node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->value = value;
	node->key = key;
    node->next = NULL;
	return (node);
}