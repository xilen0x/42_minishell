# include "minishell.h"

int	var_exists_oldpwd(t_env *env, char *variable)
{
	char	**var_ent;
	int		flag;

	flag = 0;
	var_ent = ft_split(variable, '=');
	while (env != NULL)
	{
		if (ft_strcmp(var_ent[0], env->key) == 0)
			flag = 1;
		env = env->next;
	}
	return (flag);
}

/*verifica si la variable ya existe en el env.*/
int	variable_exists_op3(t_env *env, char *variable)
{
	char	**var_ent;
	int		flag;

	flag = 0;
	var_ent = ft_split(variable, '=');
	while (env != NULL)
	{
		if (ft_strcmp(var_ent[0], env->key) == 0)
		{
			flag = 1;
			break ;
		}
		env = env->next;
	}
	return (flag);
}

/*verifica si la variable ya existe en el env y la actualiza de ser así(caso +=)*/
int variable_exists_op2(t_env *env, char *variable)
{
	char	**var_ent1;
	char	**var_ent2;
	int		flag;
	char	*new_val;

	var_ent1 = ft_split(variable, '+');
	var_ent2 = ft_split(var_ent1[1], '=');
	flag = 0;
	while (env != NULL)
	{
		if (ft_strcmp(var_ent1[0], env->key) == 0)
		{
			new_val = ft_strjoin(env->val, var_ent2[0]);
			free(env->val);
			env->val = new_val;
			flag = 1;
			break ;
		}
		env = env->next;
	}
	free_arr2d(var_ent1);
	free_arr2d(var_ent2);
	return (flag);
}

/*verifica si la variable ya existe en el env y la actualiza de ser así(caso =)*/
int	variable_exists(t_env **env, char *variable)
{
	char	**var_ent;
	int		flag;
	t_env	*current;

	var_ent = ft_split(variable, '=');
	flag = 0;
	current = *env;

	if (var_ent == NULL || var_ent[0] == NULL)
	{
		if (var_ent)
			free_arr2d(var_ent);
		return (0);
	}
	while (current != NULL)
	{
		if (ft_strcmp(var_ent[0], current->key) == 0)
		{
			// free(current->val);
			// current->val = ft_strdup(var_ent[0]);
			current->val = ft_strdup(var_ent[1]);
			flag = 1;
			break ;
		}
		current = current->next;
	}
	free_arr2d(var_ent);
	return (flag);
}
