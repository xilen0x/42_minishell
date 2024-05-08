#include "minishell.h"

/*--Returns a new node initialized with the arguments--*/
t_tok	*tok_new_node(char *str, int type)
{
	t_tok	*node;

	node = (t_tok *)p_malloc(sizeof(t_tok));
	node->str = str;
	node->type = type;
    node->next = NULL;
	return (node);
}