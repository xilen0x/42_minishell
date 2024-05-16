#include "minishell.h"

/*cambia al directorio home del usuario */
static int	go_home(void)
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
	return (0);
}

/*cambia al directorio raiz */
// static int	go_root(void)
// {
// 	if (chdir("/") != 0)
// 	{
// 		perror("chdir() error");
// 		return (1);
// 	}
// 	return (0);
// }

// /*cambia al directorio padre */
// static int	go_parent(void)
// {
// 	if (chdir("..") != 0)
// 	{
// 		perror("chdir() error");
// 		set_exit_status(1);
// 		return (1);
// 	}
// 	return (0);
// }

// /*cambia al directorio anterior(si existe) */
// static int	go_old_pwd(void)
// {

// 	if (chdir("OLDPWD") != 0)
// 	{
// 		perror("cd: OLDPWD not set");
// 		set_exit_status(1);
// 		return (1);
// 	}
// 	return (0);
// }

/*cambia a un directorio especifico */
int	go_path(t_cmd *cmd)
{
	if (chdir(cmd->commands[1]) != 0)
	{
		ft_msgs(2, cmd);
		//set_exit_status(1);
		return (1);
	}
	return (0);
}

/*Funcion que cambia de directorio al home del usuario en el caso de 'cd'
o a una ruta absoluta o relativa*/
int	builtin_cd(t_cmd	*cmd, t_env **env)
{
	//cmd = cmd;
	if ((size_arr2d(cmd->commands)) == 1)// cd only
		go_home();
	else if (ft_strcmp(cmd->commands[1], "~") == 0)
		go_home();
	else if (ft_strcmp(cmd->commands[1], "-") == 0)//no terminado
		old_pwd();
	else
		go_path(cmd);
	get_pwd(*env);
	//set_exit_status(0);
	return (0);
}
