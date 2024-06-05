/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:48:05 by castorga          #+#    #+#             */
/*   Updated: 2024/05/28 10:48:12 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*function that search by the 'PATH' word and split the content*/
char	**get_paths(t_env *env)
{
	char	**full_path;

	full_path = NULL;
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
		{
			full_path = ft_split(env->val, ':');
			break ;
		}
		env = env->next;
	}
	return (full_path);
}

/*function that create the fullpath of the command and verify if exist
in order to save it or not - part2*/
int	search_command_path_core(t_cmd *cmd, t_exe *exe)
{
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (exe->paths[i] != NULL)
	{
		cmd_path = ft_strjoin("/", cmd->commands[0]);
		full_path = ft_strjoin(exe->paths[i], cmd_path);
		free(cmd_path);
		if (full_path == NULL)
			return (-1);
		if (access(full_path, F_OK) == 0)
		{
			exe->cmd_fullpath = full_path;
			return (0);
		}
		free(full_path);
		i++;
	}
	return (1);
}

/*function that create the fullpath of the command and verify if exist
in order to save it or not - part1*/
int	search_command_path(t_cmd *cmd, t_exe *exe)
{
	if (ft_strchr(cmd->commands[0], '/'))
	{
		exe->cmd_fullpath = ft_strdup(cmd->commands[0]);
		return (0);
	}
	search_command_path_core(cmd, exe);
	return (1);
}
