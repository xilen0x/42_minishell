#include "minishell.h"

/*Update env after moving to new location with cd*/
t_env	*update_env(t_env *env, char *key, char *val)
{
	t_env	*current;
	t_env	*new_env;

	current = env;
	while (current != NULL)
	{
		if (ca_strcmp(key, current->key) == 0)
		{
			free(current->val);
			current->val = ft_strdup(val);
			return (env);
		}
		current = current->next;
	}
	// Si no se encontró la variable de entorno, agregarla al final de la lista
	new_env = lstnew(key, val);
	lstadd_back(&env, new_env);
	return (env);
}

/*Funcion que retorna el path actual(pwd). Utiliza para ello la funcion getcwd*/
int	builtin_pwd(t_shell *shell)
{
	char	*current_wd;

	current_wd = getcwd(NULL, 0);
	if (!current_wd)
	{
		perror("getcwd");
		free(current_wd);
	}
	*shell->link_env = *update_env(shell->link_env, "PWD", current_wd);
	printf("%s\n", current_wd);
	set_exit_status(0);
	free(current_wd);
	return (0);
}

/*actualiza la variable PWD del entorno*/
int	get_pwd(t_shell *shell)
{
	char	*current_wd;

	current_wd = getcwd(NULL, 0);
	if (!current_wd)
	{
		perror("getcwd");
		free(current_wd);
	}
	*shell->link_env = *update_env(shell->link_env, "PWD", current_wd);
	free(current_wd);
	return (0);
}
