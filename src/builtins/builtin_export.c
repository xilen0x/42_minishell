/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:45:46 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 16:45:50 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	create_variable(char *cmd, t_env **env)
{
	char	**tokens;
	t_env	*new_var;

	tokens = ft_split(cmd, '=');
	if (tokens && tokens[0] && tokens[1])
	{
		if (!variable_exists(env, tokens))
		{
			new_var = lstnew(tokens[0], tokens[1]);
			lstadd_back(env, new_var);
		}
		free_arr2d(tokens);
	}
	else if (tokens && tokens[0])
	{
		if (!variable_exists_op3(*env, tokens[0]))
		{
			new_var = lstnew(tokens[0], " ");
			lstadd_back(env, new_var);
		}
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

/*Funcion que agrega una nueva variable de entorno si corresp.*/
int	builtin_export_core(t_cmd *cmd, t_env **env)
{
	int	i;
	int	chk_exp;

	i = 1;
	while (cmd->commands[i] != NULL)
	{
		if (check_syntax(cmd->commands[i]))
		{
			ft_msgs(5, cmd);
			return (1);
		}
		chk_exp = check_export(cmd->commands[i]);
		if ((chk_exp == 1) || (chk_exp == 3))
			create_variable(cmd->commands[i], env);
		else if (chk_exp == 2) // '+='
			overwrite_variable(*env, cmd->commands[i]);
		else
			return (1);
		i++;
	}
	return (0);
}

int	builtin_export(t_cmd *cmd, t_env **env)
{
	if (size_arr2d(cmd->commands) == 1)
		just_export(*env);
	else
		builtin_export_core(cmd, env);
	g_get_signal = 0;
	return (0);
}
