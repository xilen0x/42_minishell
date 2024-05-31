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

/*cambia al directorio home del usuario */
static int	go_home(void)
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
	g_get_signal = 0;
	return (0);
}

/*get information about a file*/
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

// int	change_to_opcions(t_cmd	*cmd)
// {
// 	if ((size_arr2d(cmd->commands)) == 1)
// 		{
// 			go_home();
// 		return (0);}
// 	else if (ft_strcmp(cmd->commands[1], "~") == 0)
// 		{
// 			go_home();
// 		return (0);}
// 	else if (ft_strcmp(cmd->commands[1], "-") == 0)
// 		{
// 			set_old_pwd();
// 		return (0);}
// 	else if (ft_strcmp(cmd->commands[1], ".") == 0)
// 		return (0);
// 	else if ((ft_strcmp(cmd->commands[1], " ") == 0) || \
// 			(ft_strcmp(cmd->commands[1], " / ") == 0))
// 	{
// 		ft_msgs(4, cmd);
// 		return (1);
// 	}
// 	return (0);
// }

/*Change to a specific directory accordingly the parameter*/
int	builtin_cd(t_cmd	*cmd, t_env **env)
{
	char	*current_wd;

	current_wd = "";
	if ((size_arr2d(cmd->commands)) == 1)
		go_home();
	else if (ft_strcmp(cmd->commands[1], "~") == 0)
		go_home();
	else if (ft_strcmp(cmd->commands[1], "-") == 0)
		set_old_pwd();
	else if (ft_strcmp(cmd->commands[1], ".") == 0)
		return (0);
	else if ((ft_strcmp(cmd->commands[1], " ") == 0) || \
			(ft_strcmp(cmd->commands[1], " / ") == 0))
	{
		ft_msgs(4, cmd);
		return (1);
	}
	else
	{
		current_wd = getcwd(NULL, 0);
		go_path(cmd);
	}
	update_pwd(*env);
	update_oldpwd(*env, current_wd);
	if (current_wd != NULL)
	{
		free(current_wd);
		return (0);
	}
	else
		return (0);
}


