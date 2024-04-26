#include "minishell.h"

/* Función para imprimir solo keys del env */
void	ft_print_keys(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s\n", env_struct->key);
		env_struct = env_struct->next;
	}
}

/* Función para imprimir solo los values del env */
void	ft_print_values(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s\n", env_struct->val);
		env_struct = env_struct->next;
	}
}

/*funcion que imprime la lista env*/
void	ft_printstack(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s=%s\n", env_struct->key, env_struct->val);
		env_struct = env_struct->next;
	}
}