/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:05:34 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 17:05:39 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* removes environment variables specified in the command, checking their 
syntax and existence, and sets a status flag based on the result.*/
static int	builtin_unset_core(t_cmd *cmd, t_env **env, int *flag)
{
	int	chk_exp;
	int	i;

	i = 1;
	while (cmd->commands[i] != NULL)
	{
		if (check_syntax(cmd->commands[i]))
			return (1);
		chk_exp = check_export(cmd->commands[i]);
		if (chk_exp == 1 || chk_exp == 2)
			return (0);
		else
		{
			if (!(variable_exists_op3(*env, cmd->commands[i])))
				*flag = 1;
			else
			{
				env_delone(env, &cmd->commands[i], &free);
				*flag = 2;
			}
		}
		i++;
	}
	return (0);
}

/*builtin unset*/
int	builtin_unset(t_cmd *cmd, t_env **env)
{
	int	flag;

	flag = 0;
	if (size_arr2d(cmd->commands) == 1)
	{
		set_exit_status(0);
		return (0);
	}
	else
	{
		if (builtin_unset_core(cmd, env, &flag))
		{
			ft_msgs(5, cmd);
			return (1);
		}
		builtin_unset_core(cmd, env, &flag);
	}
	set_exit_status(0);
	return (0);
}
