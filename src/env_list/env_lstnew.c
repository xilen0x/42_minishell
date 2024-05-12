#include "minishell.h"

//Returns a malloced 't_env' new node initialized with the arguments
t_env	*lstnew(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)p_malloc(sizeof(t_env));
	new_node->key = ft_strdup(key);
	new_node->val = ft_strdup(value);
	new_node->next = NULL;
	return (new_node);
}