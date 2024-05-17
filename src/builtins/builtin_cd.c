#include "minishell.h"

/*cambia al directorio home del usuario */
static int	go_home(t_cmd *cmd, t_env **env)
{
	char	*home_dir;

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
	set_old_pwd(cmd, *env);
	return (0);
}

/*cambia a un directorio especifico */
int	go_path(t_cmd *cmd, t_env **env)
{
	if (chdir(cmd->commands[1]) != 0)
	{
		ft_msgs(2, cmd);
		//set_exit_status(1);
		return (1);
	}
	set_old_pwd(cmd, *env);
	return (0);
}

/*Funcion que cambia de directorio al home del usuario en el caso de 'cd'
o a una ruta absoluta o relativa*/
int	builtin_cd(t_cmd	*cmd, t_env **env)
{
	//cmd = cmd;
	if ((size_arr2d(cmd->commands)) == 1)// cd only
		go_home(cmd, env);
	else if (ft_strcmp(cmd->commands[1], "~") == 0)
		go_home(cmd, env);
	else if (ft_strcmp(cmd->commands[1], "-") == 0)//no terminado
		get_old_pwd(cmd, *env);
	else
		go_path(cmd, env);
	get_pwd(*env);
	//set_exit_status(0);
	return (0);
}

