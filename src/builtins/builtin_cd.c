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
	return (0);
}

/* Cambia a un directorio especifico */
int	go_path(t_cmd *cmd, t_env **env)
{
	(void)env;
	if (!exist_cwd())
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
		go_home();
	else if (ft_strcmp(cmd->commands[1], "~") == 0)
		go_home();
	else if (ft_strcmp(cmd->commands[1], "-") == 0)
		set_old_pwd(cmd, *env);
	else if (ft_strcmp(cmd->commands[1], ".") == 0)
		return (0);
	else
	{
		current_wd = getcwd(NULL, 0);
		go_path(cmd, env);
	}
	update_pwd(*env);
	update_oldpwd(*env, current_wd);
	return (0);
}
