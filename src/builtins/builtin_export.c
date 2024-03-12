# include "minishell.h"

/*Funcion que imprime el export(la copia)*/
int	print_builtin_export(t_env env)
{
	int	i;

	i = 0;
	while (env.export_cpy[i])
	{
		printf ("%s\n", env.export_cpy[i]);
		i++;
	}
	return (0);
}

/*int	builtin_export_with_arg(t_env env)
{
	int	i;

	i = 0;
	while (env.env_to_build->path[i])
	{
		if (ft_strcmp(env.env_to_build->path[i], '='))
		{
			i = 0;
			env.env_cpy[i] = 
		}
		i++;
	}
}*/

/*builtin que agrega el string "declare -x " al output del export, al ejecutar 
export sin argumentos*/
int	builtin_export(t_env env, int ac)
{
	int		i;
	size_t	len;
	char	*new_env_var;

	i = 0;
	if (ac == 2)
	{
		while (env.export_cpy[i])
		{
			len = ft_strlen(env.export_cpy[i]);
			new_env_var = (char *)malloc((len + 12) * sizeof(char));
			if (!new_env_var)
				return (-1);
			ft_memcpy(new_env_var, "declare -x ", 11);
			ft_memcpy(new_env_var + 11, env.export_cpy[i], len + 1);
			free(env.export_cpy[i]);
			env.export_cpy[i] = new_env_var;
			i++;
		}
		print_builtin_export(env);
	}
	/*else
		builtin_export_with_arg(env);*/
	return (0);
}
