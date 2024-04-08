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

/*Funcion que imprime el nuevo env*/
int	print_builtin_export_with_arg(char	**new_env)
{
	int	i;

	i = 0;
	while (new_env[i])
	{
		printf ("%s\n", new_env[i]);
		i++;
	}
	return (0);
}

int	if_exist_builtin_export(t_cmd *cmd, t_env *env)
{
	int		i;
	size_t	len;

	len = ft_strlen(*cmd->command_and_arg) + 1;
	i = 0;
	while (env->env_cpy[i])
	{
		if (ca_strcmp(env->env_cpy[i], *cmd->command_and_arg) == 0)
		{
			ft_memcpy(env->env_cpy, cmd->command_and_arg, len);
			return (0);
		}
		i++;
	}
	return (1);
}


/*Funcion que agrega una nueva variable de entorno*/
int	builtin_export_with_arg(t_cmd *cmd, t_env *env)
{
	int		i;
	char	**new_env;
	int		len;

	if (if_exist_builtin_export(cmd, env))//CORREGIR : esta agregando a la variable pero no sobreescribiendola si es q existe!
	{
		i = 0;
		while (env->env_cpy[i])
			i++;
		len = i + 2;
		new_env = malloc(sizeof(char *) * (len + 1));
		if (!new_env)
			return (0);
		i = 0;
		while (env->env_cpy[i])
		{
			new_env[i] = ft_strdup(env->env_cpy[i]);
			if (!new_env[i])
				return (0);
			i++;
		}
		new_env[i] = ft_strdup(*cmd->command_and_arg);
		if (!new_env[i])
			return (0);
		new_env[i + 1] = NULL;
		free(env->env_cpy);
		env->env_cpy = new_env;
	}
	print_builtin_export_with_arg(env->env_cpy);
	return (0);
}


/*builtin que agrega el string "declare -x " al output del export, al ejecutar 
export sin argumentos*/
int	builtin_export(t_cmd *cmd, t_env env)
{
	int		i;
	//size_t	len;
	//char	*new_env_var;

	i = 0;
	if (size_arr2d(cmd->command_and_arg) == 1)
	{
		while (env.env_cpy[i])
		{
			printf("declare -x %s\n", env.env_cpy[i]);
			i++;
		}
		return (0);
	}
	// else
	// {
	// 	while (env.export_cpy[i])
	// 	{
	// 		len = ft_strlen(env.export_cpy[i]);
	// 		new_env_var = (char *)malloc((len + 12) * sizeof(char));
	// 		if (!new_env_var)
	// 			return (-1);
	// 		ft_memcpy(new_env_var, "declare -x ", 11);
	// 		ft_memcpy(new_env_var + 11, env.export_cpy[i], len + 1);
	// 		free(env.export_cpy[i]);
	// 		env.export_cpy[i] = new_env_var;
	// 		i++;
	// 	}
	// 	print_builtin_export(env);
	// }
	// else// si viene por ej. 'export TEST=10'
	//  	builtin_export_with_arg(cmd, &env);
	return (0);
}

/*
	NOTA: Buildin 'export' la he dejado en pausa hasta tener la estructura 
		definitiva, al igual que 'unset'
*/
