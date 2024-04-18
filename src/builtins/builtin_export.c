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

int	ca_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (1);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i] && str[i] == needle[j] && needle[j] && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (1);
		i = i + 1 - j;
	}
	return (0);
}

int	variable_exists(t_env *env, char *variable)
{
	int		i;
	char	**tmp;
	int		ret;

	i = 0;
	ret = 0;
	tmp = ft_split(variable, '=');
	while (env != NULL)
	{
		if (ca_strcmp(tmp[0], env->key) == 0)
			ret = 1;
		i++;
		env = env->next;
	}
	return (ret);
}

static int	just_export(t_env *env)
{
	while (env != NULL)
	{
		printf("declare -x %s=\"%s\"\n", env->key, env->val);
		env = env->next;
	}
	return (0);
}
/*Funcion que agrega una nueva variable de entorno si corresp.*/
int	builtin_export(t_cmd *cmd, t_env *env)
{
	int		i;

	i = 0;
	if (size_arr2d(cmd->command_and_arg) == 1)
		just_export(env);
	else
	{
		i = 0;
		if (check_export(cmd->command_and_arg[1]) == 1)
		{
			//variable_exists(env, cmd->command_and_arg[1] == 0);
			if (variable_exists(env, cmd->command_and_arg[1]))
			{
				printf("SI existe la variable!\n");
				// //len = size_arr2d(&cmd->command_and_arg[1]);
				// len = 0;
				// while (cmd->command_and_arg[1][len] != '=')
				// 	len++;
				// while (ft_strnstr(env->env_cpy[i], cmd->command_and_arg[1], len) != NULL)
				// 	i++;
				// env->env_cpy[i] = ft_strdup(cmd->command_and_arg[1]);//tiene q sobrescribirla
			}
			else
			{
				printf("NO existe la variable!\n");
				env = 
			}
			return (0);
		}
		else if (check_export(cmd->command_and_arg[1]) == 2)
		{
			printf("soy un +=\n");
			// if (variable_exists(*env, cmd->command_and_arg[1]))
			// {
			// 	//printf("SI existe la variable!\n");
			// }
			// else
			// {
			// 	//printf("NO existe la variable!\n");
			// 	//env.env_cpy = add_one_arr2d(cmd->command_and_arg, cmd->command_and_arg[1]);
			// }
			// return (0);
		}
		else
			ft_msgs(5);
	}
	return (0);
}
