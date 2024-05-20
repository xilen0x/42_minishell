#include "minishell.h"

/*cambia al directorio home del usuario */
static int	go_home(t_cmd *cmd, t_env **env)
{
	char	*home_dir;

	(void)env;
	(void)cmd;
	home_dir = getenv("HOME");
	if (home_dir == NULL)
	{
		perror("getenv() error");
		//set_exit_status(1);
		return (1);
	}
	if (chdir(home_dir) != 0)
	{
		perror("chdir() error");
		//set_exit_status(1);
		return (1);
	}
	// set_old_pwd(cmd, *env);
	return (0);
}

/* Cambia a un directorio especifico */
int	go_path(t_cmd *cmd, t_env **env)
{
	(void)env;
	if (exist_cwd() == 1)
		return (1);
	else
	{
		if (chdir(cmd->commands[1]) != 0)
			return (1);
	}
	return (0);
}

/*Funcion que cambia de directorio segun parámetro*/
int	builtin_cd(t_cmd	*cmd, t_env **env)
{
	char	*current_wd;

	current_wd = "";
	if ((size_arr2d(cmd->commands)) == 1)// cd only
		go_home(cmd, env);
	else if (ft_strcmp(cmd->commands[1], "~") == 0)
		go_home(cmd, env);
	else if (ft_strcmp(cmd->commands[1], "-") == 0)
		set_old_pwd(cmd, *env);
	else if (ft_strcmp(cmd->commands[1], ".") == 0)
	{
		write(2, "cd: error retrieving current directory: ", 40);
		write(2, "getcwd: cannot access parent directories: ", 44);
		write(2, "No such file or directory\n", 27);
		return (0);
	}
	else
	{
		current_wd = getcwd(NULL, 0);
		go_path(cmd, env);
	}
	update_pwd(*env);
	get_old_pwd(current_wd, *env);
	// update_oldpwd(*env);
	//set_exit_status(0);
	return (0);
}
