# include "minishell.h"

/*check if export argument comes with = or += */
unsigned int	check_export(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && (ft_isalpha(arg[i]) || arg[i] == '_' || ft_isdigit(arg[i])))
		i++;
	if (arg[i] == '+')
	{
		if (ft_strncmp(&arg[i], "+=", 2) == 0)
			return (2);
	}
	else if (arg[i] == '=')
		return (1);
	return (0);
}

// void	update_env(t_env *env, char *key, char *val)
// {
// 	(void)key;
// 	t_env		*aux;

// 	aux = env;
// 	if (aux->val)
// 		free (aux->val);
// 	if (val)
// 		aux->val = ft_strdup(val);
// 	else
// 		aux->val = ft_strdup("");
// 	return ;
// }

/*verifica si la variable ya existe en el env.*/
int	variable_exists_op3(t_env *env, char *variable)
{
	int		i;
	char	**var_ent;
	int		flag;

	i = 0;
	flag = 0;
	var_ent = ft_split(variable, '=');
	while (env != NULL)
	{
		if (ft_strcmp(var_ent[0], env->key) == 0)
		{
			//env_delone(&env, env, &free); //y la elimina de ser así
			flag = 1;
			break ;
		}
		i++;
		env = env->next;
	}
	return (flag);
}

/*verifica si la variable ya existe en el env y la actualiza de ser así(caso +=)*/
int	variable_exists_op2(t_env *env, char *variable)
{
	int		i;
	char	**var_ent1;
	char	**var_ent2;
	int		flag;

	i = 0;
	flag = 0;
	var_ent1 = ft_split(variable, '+');
	var_ent2 = ft_split(var_ent1[1], '=');
	while (env != NULL)
	{
		if (ft_strcmp(var_ent1[0], env->key) == 0)
		{
			env->val = ft_strjoin(env->val,var_ent2[0]);//join
			flag = 1;
			break ;
		}
		i++;
		env = env->next;
	}
	return (flag);
}

/*verifica si la variable ya existe en el env y la actualiza de ser así(caso =)*/
int	variable_exists(t_env *env, char *variable)
{
	int		i;
	char	**var_ent;
	int		flag;

	i = 0;
	flag = 0;
	var_ent = ft_split(variable, '=');
	while (env != NULL)
	{
		if (ft_strcmp(var_ent[0], env->key) == 0)
		{
			env->val = var_ent[1];
			flag = 1;
		}
		i++;
		env = env->next;
	}
	// free_arr2d(var_ent);
	return (flag);
}

int	var_exists_oldpwd(t_env *env, char *variable)
{
	int		i;
	char	**var_ent;
	int		flag;

	i = 0;
	flag = 0;
	var_ent = ft_split(variable, '=');
	while (env != NULL)
	{
		if (ft_strcmp(var_ent[0], env->key) == 0)
			flag = 1;
		i++;
		env = env->next;
	}
	// free_arr2d(var_ent);
	return (flag);
}

/*print the export output(without argument)*/
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
int	builtin_export(t_cmd *cmd, t_env **env)
{
	char	**tokens;
	char	**tokens2;
	char	*key;
	char	*value;
	int		chk_exp;

	if (size_arr2d(cmd->command_and_arg) == 1)
		just_export(*env);
	else
	{
		chk_exp = check_export(cmd->command_and_arg[1]);
		if (chk_exp == 1)// =
		{
			if (!(variable_exists(*env, cmd->command_and_arg[1])))
			{
				//printf("= NO existe la variable!\n");
				tokens = ft_split(cmd->command_and_arg[1], '=');
				if (tokens != NULL && tokens[0] != NULL && tokens[1] != NULL)
				{
					key = tokens[0];
					value = tokens[1];
					lstadd_back(env, lstnew(key, value));
				}
				free_arr2d(tokens);
			}
			return (0);
		}
		else if (chk_exp == 2)// +=
		{
			if (!(variable_exists_op2(*env, cmd->command_and_arg[1])))
			{
				//printf("+= NO existe la variable!\n");
				tokens = ft_split(cmd->command_and_arg[1], '+');
				tokens2 = ft_split(tokens[1], '=');
				if (tokens != NULL && tokens[0] != NULL && tokens[1] != NULL)
				{
					key = tokens[0];
					value = tokens2[0];
					lstadd_back(env, lstnew(key, value));
				}
				free_arr2d(tokens);
			}
			return (0);
		}
	}
	return (0);
}
