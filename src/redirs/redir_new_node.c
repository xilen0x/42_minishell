#include "minishell.h"

/*------Returns a new initialized t_redir node-----*/
t_redir	*redir_new_node(char *str, int redir_type)
{
	t_redir	*node;

	node = (t_redir *)malloc(sizeof(t_redir));
	if (!node)
		return (NULL);
    node->filename = str;
    node->redir_type = redir_type;
    node->next = NULL;
	return (node);
}