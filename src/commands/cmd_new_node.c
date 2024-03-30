#include "minishell.h"

/*------Returns a new NULL initialized t_cmd node-----*/
t_cmd	*cmd_new_node(void)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
    node->command_and_arguments = NULL;
    node->io_redirect_list = NULL;
    node->next = NULL;
	return (node);
}