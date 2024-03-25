
#include "minishell.h"

/*------RETORNA UN NUEVO NODO INICIALIZADO CON LOS ARGUMENTOS---------*/
t_lst	*lstnew_node(char *val, int key)
{
	t_lst	*node;

	 node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->val = val;
	node->key = key;
    node->next = NULL;
	return (node);
}