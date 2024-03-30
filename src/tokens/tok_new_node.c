
#include "minishell.h"

/*--Returns a new node initialized with the arguments--*/
t_tok	*tok_new_node(char *str, int key)
{
	t_tok	*node;

	 node = (t_tok *)malloc(sizeof(t_tok));
	if (!node)
		return (NULL);
	node->str = str;
	node->type = key;
    node->next = NULL;
	return (node);
}