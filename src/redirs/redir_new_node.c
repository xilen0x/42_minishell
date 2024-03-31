#include "minishell.h"

/*------Returns a new NULL initialized t_redir node-----*/
t_redir	*redir_new_node(char *str, int red_io)
{
	t_redir	*node;

	node = (t_redir *)malloc(sizeof(t_redir));
	if (!node)
		return (NULL);
    node->filename = str;
    node->red_io = red_io;
    node->next = NULL;
	return (node);
}