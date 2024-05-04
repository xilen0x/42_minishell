#include "minishell.h"

/*------Returns a new initialized t_redir node-----*/
t_redir	*redir_new_node(char *str, int redir_type)
{
	t_redir	*node;

	node = (t_redir *)p_malloc(sizeof(t_redir));
    node->filename = str;
    node->redir_type = redir_type;
    node->next = NULL;
	return (node);
}