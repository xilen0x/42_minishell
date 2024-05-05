#include "minishell.h"

/*Retorna el valor de env_key si esta se encuentra en envlist, sino retorna NULL*/
char *get_env_val(char *env_key, t_env *envlist)
{
	char	*val_aux;

	val_aux = NULL;
	if (env_key == NULL)//proteccion por si despues de $ viene un num
		return (NULL);
	while (envlist)
	{
		if (ft_strcmp(envlist->key, env_key) == 0)
		{
			val_aux = ft_strdup(envlist->val);//Quizas debiera ser un strdup, para despues liberarlo sin afectar al env?
			return (val_aux);
		}
		envlist = envlist->next;
	}
	return (val_aux);
}