/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:58:14 by castorga          #+#    #+#             */
/*   Updated: 2024/05/29 10:58:18 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*according to the command received, redirects to its corresponding building.*/
int	builtins(t_cmd *cmd, t_exe exe, t_env **env)
{
	if (ft_strcmp(*cmd->commands, "exit") == 0)
	{
		builtin_exit(cmd);
		exit (0);
	}
	else if ((ft_strcmp(*cmd->commands, "pwd") == 0) || \
		(ft_strcmp(*cmd->commands, "PWD") == 0))
		builtin_pwd(*env);
	else if (ft_strcmp(*cmd->commands, "cd") == 0)
		builtin_cd(cmd, env);
	else if ((ft_strcmp(*cmd->commands, "env") == 0) || \
	(ft_strcmp(*cmd->commands, "ENV") == 0))
		builtin_env(cmd, exe, *env);
	else if ((ft_strcmp(*cmd->commands, "echo") == 0) || \
	(ft_strcmp(*cmd->commands, "ECHO") == 0))
		builtin_echo(cmd);
	else if (ft_strcmp(*cmd->commands, "export") == 0)
		builtin_export(cmd, env);
	else if (ft_strcmp(*cmd->commands, "unset") == 0)
		builtin_unset(cmd, env);
	else if (ft_strcmp(*cmd->commands, "help") == 0)
		help_mini();
	else
		return (0);
	return (1);
}

/*check if is builtin(1) or not(0)*/
int	is_builtins(t_cmd *cmd)
{
	if (ft_strcmp(*cmd->commands, "exit") == 0)
		return (1);
	else if ((ft_strcmp(*cmd->commands, "pwd") == 0) || \
		(ft_strcmp(*cmd->commands, "PWD") == 0))
		return (1);
	else if (ft_strcmp(*cmd->commands, "cd") == 0)
		return (1);
	else if ((ft_strcmp(*cmd->commands, "env") == 0) || \
	(ft_strcmp(*cmd->commands, "ENV") == 0))
		return (1);
	else if ((ft_strcmp(*cmd->commands, "echo") == 0) || \
	(ft_strcmp(*cmd->commands, "ECHO") == 0))
		return (1);
	else if (ft_strcmp(*cmd->commands, "export") == 0)
		return (1);
	else if (ft_strcmp(*cmd->commands, "unset") == 0)
		return (1);
	else if (ft_strcmp(*cmd->commands, "help") == 0)
		return (1);
	return (0);
}
