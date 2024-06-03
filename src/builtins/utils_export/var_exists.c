/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:25:50 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 15:25:54 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*checks if the variable oldpwd already exists in the env.*/
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
	free_arr2d(var_ent);
	return (flag);
}

/*checks if the variable already exists in the env. op3*/
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
	free_arr2d(var_ent);
	return (flag);
}

/*checks if the variable already exists in the env. op4*/
t_env	*variable_exists_op4(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strcmp(key, env->key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

/*checks if the variable already exists in the env. and updates it,
 if applicable(case +=)*/
int	variable_exists_op2(t_env *env, char *variable)
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

/*checks if the variable already exists in the env. and updates it,
 if applicable(case =)*/
int	variable_exists(t_env **env, char **variable)
{
	char	**var_ent;
	int		flag;
	t_env	*current;

	var_ent = ft_split(*variable, '=');
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
			current->val = ft_strdup(variable[1]);
			flag = 1;
			break ;
		}
		current = current->next;
	}
	free_arr2d(var_ent);
	return (flag);
}
