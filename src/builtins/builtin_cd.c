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

// /*cambia al directorio anterior(si existe) */
static int	go_old_pwd(t_cmd *cmd, t_env *env)
{
	(void)cmd;
	if (!(variable_exists_op3(env, "OLDPWD")))
		printf("NO existe la variable OLDPWD!\n");//cambiar luego por write("\n")
	else
	{
		printf("Existe la variable OLDPWD!\n");
		// if (chdir("OLDPWD") != 0)
		// {
		// 	// perror("cd: OLDPWD not set");
		// 	ft_msgs(4, cmd);
		// 	// set_exit_status(1);
		// 	return (1);
		// }
	}
	return (0);
}

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
		go_old_pwd(cmd, *env);
		// old_pwd();
	else
		go_path(cmd);
	get_pwd(*env);
	//set_exit_status(0);
	return (0);
}
