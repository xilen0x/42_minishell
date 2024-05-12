#include "minishell.h"

//Removes a node from a 't-env' list
void	env_delone(t_env **env, char **node_to_del, void (*del)(void*))
{
	t_env	*current;
	t_env	*prev;

	current = *env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, *node_to_del) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env = current->next;
			del(current->key);
			del(current->val);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
/*
	env = update_env(env, "PWD", current_wd);
	free(current_wd);
*/