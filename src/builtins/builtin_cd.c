/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:51:57 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 15:52:00 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Change to the user's home directory*/
int	go_home(void)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (home_dir == NULL)
	{
		perror("getenv() error");
		return (1);
	}
	if (chdir(home_dir) != 0)
	{
		perror("chdir() error");
		return (1);
	}
	// g_get_signal = 0;
	return (0);
}

/*Get information about a file*/
int	get_info_file(t_cmd *cmd, struct stat *info_f)
{
	if (stat(cmd->commands[1], info_f) == -1)
	{
		ft_msgs(4, cmd);
		return (1);
	}
	if (!S_ISDIR(info_f->st_mode) || \
		!(info_f->st_mode & S_IRUSR) || !(info_f->st_mode & S_IXUSR))
	{
		ft_msgs(7, cmd);
		return (1);
	}
	return (0);
}

/* Change to a specific directory */
int	go_path(t_cmd *cmd)
{
	struct stat	info_f;

	if (!exist_cwd())
		return (1);
	else
	{
		if (cmd->commands[1] == NULL)
			return (1);
		get_info_file(cmd, &info_f);
		if (chdir(cmd->commands[1]) == -1)
		{
			return (1);
		}
	}
	return (0);
}

/*Change to the previous directory*/
static int	change_directory(t_cmd *cmd, char **current_wd)
{
	*current_wd = getcwd(NULL, 0);
	if (*current_wd == NULL)
	{
		perror("getcwd() error");
		return (1);
	}
	if (go_path(cmd) != 0)
	{
		free(*current_wd);
		*current_wd = NULL;
		return (1);
	}
	return (0);
}

/*Change to a specific directory accordingly the parameter*/
int	builtin_cd(t_cmd *cmd, t_env **env)
{
	char	*current_wd;

	current_wd = NULL;
	if (handle_no_argument(cmd) == 1)
		return (1);
	if (handle_tilde(cmd) == 1)
		return (1);
	if (handle_dash(cmd) == 1)
		return (1);
	if (handle_dot(cmd) == 1)
		return (0);
	if (handle_invalid_path(cmd) == 1) 
		return (1);
	if (change_directory(cmd, &current_wd) != 0)
		return (1);
	update_environment(*env, current_wd);
	return (free_current_wd(current_wd));
}
