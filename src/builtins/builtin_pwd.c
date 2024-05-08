#include "minishell.h"

/*Update env after moving to new location with cd*/
t_env	*update_env(t_env *env, char *key, char *val)
{
	t_env	*current;
	t_env	*new_env;

	current = env;
	while (current != NULL)
	{
		if (ft_strcmp(key, current->key) == 0)
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
int	builtin_pwd(t_env *env)
{
	char	*current_wd;

	current_wd = getcwd(NULL, 0);
	*env = *update_env(env, "PWD", current_wd);
	printf("%s\n", current_wd);
	set_exit_status(0);
	free(current_wd);
	return (0);
}

/*actualiza la variable PWD del entorno*/
int	get_pwd(t_env *env)
{
	char	*current_wd;

	current_wd = getcwd(NULL, 0);
	if (!current_wd)
	{
		perror("getcwd");
		free(current_wd);
	}
	env = update_env(env, "PWD", current_wd);
	free(current_wd);
	return (0);
}

/*Funcion que retorna el path anterior(OLDPWD). Utiliza para ello la funcion getcwd*/
// int	old_pwd(t_shell *shell)
// {
// 	char	*old_wd;

// 	old_wd = "/";
// 	if (variable_exists(shell->link_env, shell->link_cmd->command_and_arg[1]))
// 	{
// 		printf("variable oldpwd existe\n");
// 	}
// 	// 	old_wd = getenv("OLDPWD");
// 	// 	if (chdir(old_wd) != 0)
// 	// 	{
// 	// 		perror("cd: OLDPWD not set");
// 	// 		set_exit_status(1);
// 	// 		return (1);
// 	// 	}
// 	// }
// 	else
// 	{
// 		printf("no existe oldpwd aun\n");
// 		return (1);
// 	}
// 	//*shell->link_env = *update_env(shell->link_env, "OLDPWD", old_wd);
// 	set_exit_status(0);
// 	///free(old_wd);
// 	return (0);
// }

int	old_pwd(void)
{
	char *oldpwd_value = getenv("OLDPWD"); // Obtener el valor de OLDPWD

	if (oldpwd_value == NULL)
	{
		printf("No existe la variable OLDPWD!\n");
		return (1); // Retornar 1 en caso de error
	}
	printf("Sí existe la variable OLDPWD\n");
	// Cambiar al directorio anterior
	if (chdir(oldpwd_value) != 0)
	{
		perror("chdir");
		set_exit_status(1);
		return (1); // Retornar 1 en caso de error
	}
	return (0); // Retornar 0 indicando éxito
}
