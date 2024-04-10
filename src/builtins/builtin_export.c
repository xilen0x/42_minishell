# include "minishell.h"

/*Funcion que imprime el export(la copia)*/
// int	print_builtin_export(t_env env)
// {
// 	int	i;

// 	i = 0;
// 	while (env.export_cpy[i])
// 	{
// 		printf ("%s\n", env.export_cpy[i]);
// 		i++;
// 	}
// 	return (0);
// }

// /*Funcion que imprime el nuevo env*/
// int	print_builtin_export_with_arg(char	**new_env)
// {
// 	int	i;

// 	i = 0;
// 	while (new_env[i])
// 	{
// 		printf ("%s\n", new_env[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int	if_exist_builtin_export(t_cmd *cmd, t_env *env)
// {
// 	int		i;
// 	size_t	len;

// 	len = ft_strlen(*cmd->command_and_arg) + 1;
// 	i = 0;
// 	while (env->env_cpy[i])
// 	{
// 		if (ca_strcmp(env->env_cpy[i], *cmd->command_and_arg) == 0)
// 		{
// 			ft_memcpy(env->env_cpy, cmd->command_and_arg, len);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }


/*Funcion que agrega una nueva variable de entorno*/
// int	builtin_export_with_arg(t_cmd *cmd, t_env *env)
// {
// 	int		i;
// 	char	**new_env;
// 	int		len;

// 	if (if_exist_builtin_export(cmd, env))//CORREGIR : esta agregando a la variable pero no sobreescribiendola si es q existe!
// 	{
// 		i = 0;
// 		while (env->env_cpy[i])
// 			i++;
// 		len = i + 2;
// 		new_env = malloc(sizeof(char *) * (len + 1));
// 		if (!new_env)
// 			return (0);
// 		i = 0;
// 		while (env->env_cpy[i])
// 		{
// 			new_env[i] = ft_strdup(env->env_cpy[i]);
// 			if (!new_env[i])
// 				return (0);
// 			i++;
// 		}
// 		new_env[i] = ft_strdup(*cmd->command_and_arg);
// 		if (!new_env[i])
// 			return (0);
// 		new_env[i + 1] = NULL;
// 		free(env->env_cpy);
// 		env->env_cpy = new_env;
// 	}
// 	print_builtin_export_with_arg(env->env_cpy);
// 	return (0);
// }

unsigned int	check_export(char *arg)
{
	int	i;

	i = 0;
	while ((ft_isalpha(arg[i]) == 1 || arg[i] == '_') && arg[i] != '\0')
		i++;
	if (arg[i] == '=')
		return (1);
	if (ft_strncmp(&arg[i], "+=", 2) == 0)
		return (2);
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
	if (size_arr2d(cmd->command_and_arg) == 1)// para el caso tipo 'export'
	{
		while (env.env_cpy[i])
		{
			printf("declare -x %s\n", env.env_cpy[i]);
			i++;
		}
		return (0);
	}
	//else if (ca_strchr(cmd->command_and_arg[1], '='))// para el caso tipo 'export TEST=10'
	else
	{
		if (check_export(cmd->command_and_arg[1]) == 1)
		{
			env.env_cpy = add_one_arr2d(cmd->command_and_arg, cmd->command_and_arg[1]);//aki voy!!! verificar pq no esta agregando el export al env
			// printf("soy un =\n");
			return (0);
		}
		else if (check_export(cmd->command_and_arg[1]) == 2)
		{
			//env.env_cpy = add_one_arr2d(cmd->command_and_arg, cmd->command_and_arg[1]);
			printf("soy un +=\n");
			return (0);
		}
		
		//builtin_export_with_arg(cmd, &env);
		//env.env_cpy = add_one_arr2d(cmd->command_and_arg, cmd->command_and_arg[1]);
		//env.export_cpy = add_one_arr2d(cmd->command_and_arg, cmd->command_and_arg[1]);
	}
	return (0);
}
