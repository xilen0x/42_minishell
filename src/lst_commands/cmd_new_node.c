#include "minishell.h"

/*------RETORNA UN NUEVO NODO t_comm MALLOCADO E INICIALIZADO A NULL---------*/
t_cmd	*cmd_new_node(void)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
    node->cmd_arg = NULL;
    node->fd_io = NULL;
    node->next = NULL;
	return (node);
}