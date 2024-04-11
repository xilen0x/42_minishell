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

// int	var_exist(t_cmd *cmd, t_env *env)
// {
// 	int	i;
// 	size_t	len;

// 	i = 0;
// 	len = size_arr2d(&cmd->command_and_arg[1]);
// 	while (ft_strnstr(env->env_cpy[i], cmd->command_and_arg[1], len) == NULL)
// 		i++;
// 	i = 1;
// 	while (env->env_cpy[i])
// 	{
// 		if (ca_strcmp(env->env_cpy[i], cmd->command_and_arg[1]) == 0)
// 		{
// 			printf("SI existe la variable!\n");
// 			return (1);
// 		}
// 		i++;
// 	}
// 	printf("NO existe la variable!\n");
// 	return (0);
// }

int variable_exists(t_env env, const char *variable)
{
    int i = 0;
    while (env.env_cpy[i]) {
        if (ft_strncmp(env.env_cpy[i], variable, 4) == 0)//cambiar este 4 por  el len de la variable
		{
            return 1; // La variable existe
        }
        i++;
    }
    return 0;
}

/*Funcion que agrega una nueva variable de entorno*/
int	builtin_export(t_cmd *cmd, t_env *env)
{
	int		i;

	i = 0;
	if (size_arr2d(cmd->command_and_arg) == 1)// para el caso tipo 'export'
	{
		while (env->env_cpy[i])
		{
			printf("declare -x %s\n", env->env_cpy[i]);
			i++;
		}
		return (0);
	}
	else// para el caso tipo 'export TEST=10'
	{
		//const char *variable_to_check = "MAIL";
		//if(var_exist(cmd, &env))//funcion q comprueba si existe la variable aqui...
		if (variable_exists(*env, cmd->command_and_arg[1]))
		{
			printf("SI existe la variable!\n");
		}
		else
		{
			printf("NO existe la variable!\n");
		}
		
		// if (check_export(cmd->command_and_arg[1]) == 1)
		// {
		// 	env->env_cpy = add_one_arr2d(env->env_cpy, cmd->command_and_arg[1]);
		// 	i = 0;
		// 	// while (env->env_cpy[i])
		// 	// {
		// 	// 	printf("%s\n", env->env_cpy[i]);
		// 	// 	i++;
		// 	// }
		// 	return (0);
		// }
		// else if (check_export(cmd->command_and_arg[1]) == 2)
		// {
		// 	//env.env_cpy = add_one_arr2d(cmd->command_and_arg, cmd->command_and_arg[1]);
		// 	printf("soy un +=\n");
		// 	return (0);
		// }
	}
	return (0);
}
