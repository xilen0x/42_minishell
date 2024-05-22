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
	else
		return (3);//sin = ni +=
	return (0);
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

int	create_variable(t_cmd *cmd, t_env **env)
{
	char	**tokens;
	t_env	*new_var;

	tokens = ft_split(cmd->commands[1], '=');
	if (tokens && tokens[0] && tokens[1])
	{
		if (!variable_exists(env, cmd->commands[1]))
		{
			new_var = lstnew(tokens[0], tokens[1]);
			lstadd_back(env, new_var);
		}
		// else
		// {
		// 	variable_exists(env, pipe);
		// }
		free_arr2d(tokens);
	}
	return (0);
}

int	overwrite_variable(t_env *env, char *cmd)
{
	char	**tokens;
	char	**tokens2;
	t_env	*new_var;

	tokens = ft_split(cmd, '+');
	if (tokens && tokens[0])
	{
		tokens2 = ft_split(tokens[1], '=');
		if (tokens2 && tokens2[0])
		{
			if (!variable_exists_op2(env, cmd))
			{
				new_var = lstnew(tokens[0], tokens2[0]);
				lstadd_back(&env, new_var);
			}
			free_arr2d(tokens2);
		}
		free_arr2d(tokens);
	}
	return (0);
}

int	check_syntax(t_cmd *cmd)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!(ft_isalpha(cmd->commands[1][i])))
	{
		flag = 1;
		return (1);
	}
	while (cmd->commands[1][i])
	{
		// if (ca_strchr(&cmd->commands[1][i], '/'))
		if ((cmd->commands[1][i]) < 65 || (cmd->commands[1][i] > 122))
		{
			if (cmd->commands[1][i] == '=')
				return (0);
			if ((cmd->commands[1][i] > 47) && (cmd->commands[1][i] < 58))
				return (0);
			flag = 1;
			return (1);
		}
		if ((cmd->commands[1][i]) > 90 && (cmd->commands[1][i] < 97))
		{
			flag = 1;
			return (1);
		}
			// flag = 1;
		i++;
	}
	// if (flag == 1)
	// {
		// ft_msgs(5, cmd);
		// write(2, "export: not a valid identifier\n", 30);
	// 	return (1);
	// }
	return (0);
}

/*Funcion que agrega una nueva variable de entorno si corresp.*/
int	builtin_export(t_cmd *cmd, t_env **env)
{
	int	chk_exp;
	int	i;

	i = 0;
	if (size_arr2d(cmd->commands) == 1)
		just_export(*env);
	else
	{
		while (cmd->commands[i])
		{
			if (check_syntax(cmd))
			{
				ft_msgs(5, cmd);
				return (1);
			}
			chk_exp = check_export(cmd->commands[1]);
			if (chk_exp == 1) // '='
			{
				create_variable(cmd, env);
				return (0);
			}
			else if (chk_exp == 2) // '+='
			{
				overwrite_variable(*env, cmd->commands[1]);
				return (0);
			}
			else if (chk_exp == 3)
				return (1);
			i++;
		}
	}
	return (0);
}
