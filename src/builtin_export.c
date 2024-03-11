# include "minishell.h"

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

/*builtin que imprime el environment(la copia)*/
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
			new_env_var = (char *)malloc((len + 11) * sizeof(char));
			if (!new_env_var)
			{
				perror("Error al asignar memoria");
				return (-1);
			}
			ft_memcpy(new_env_var, "declare -x ", 11);
			ft_memcpy(new_env_var + 11, env.export_cpy[i], len + 1);
			free(env.export_cpy[i]);
			env.export_cpy[i] = new_env_var;
			i++;
		}
		print_builtin_export(env);
	}
	return (0);
}
