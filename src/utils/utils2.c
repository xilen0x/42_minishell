#include "minishell.h"

// void	init_main_struct(t_shell *shell)
// {
// 	shell->link_env = NULL;
// 	shell->link_exe = NULL;
// 	//shell->link_cmd = NULL;
// 	//shell->link_redir = NULL;
// 	//shell->link_redir_t = NULL;
// 	//shell->link_tok = NULL;
// 	//g_exit_stat = 0;
// }
/*
void	ft_free_split(char **array_strings)
{
	size_t	i;

	i = 0;
	if (array_strings)
	{
		while (array_strings[i])
		{
			free(array_strings[i]);
			i++;
		}
		free(array_strings);
	}
}
*/
//Funcion que elimina una variable del entorno
void	env_delone(t_env **env, char **node_to_del, void (*del)(void*))
{
	t_env	*current;
	t_env	*prev;

	current = *env;
	prev = NULL;
	while (current)
	{
		if (ca_strcmp(current->key, *node_to_del) == 0)
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