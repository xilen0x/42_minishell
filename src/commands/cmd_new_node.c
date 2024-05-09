#include "minishell.h"

/*------Returns a new NULL initialized t_cmd node-----*/
t_cmd	*cmd_new_node(void)
{
	t_cmd	*node;

	node = (t_cmd *)p_malloc(sizeof(t_cmd));
    node->commands = NULL;
    node->redir = NULL;
    node->next = NULL;
	return (node);
}