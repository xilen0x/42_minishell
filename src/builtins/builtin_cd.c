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
	get_signal = 0;
	return (0);
}

/*
    S_ISDIR(mode): Esta macro se utiliza para verificar si el archivo 
	representado por mode es un directorio. Devuelve un valor distinto 
	de cero si mode indica un directorio; de lo contrario, devuelve cero.

    S_IRUSR: Esta macro indica los permisos de lectura del propietario 
	del archivo. Es un bit en el modo de archivo (st_mode) que indica 
	si el propietario del archivo tiene permisos de lectura. Si el bit 
	correspondiente a S_IRUSR está encendido en el modo de archivo, el 
	propietario del archivo tiene permisos de lectura.

    S_IXUSR: Esta macro indica los permisos de ejecución del propietario 
	del archivo. Es un bit en el modo de archivo (st_mode) que indica si 
	el propietario del archivo tiene permisos de ejecución. Si el bit 
	correspondiente a S_IXUSR está encendido en el modo de archivo, el 
	propietario del archivo tiene permisos de ejecución.
*/

/* Cambia a un directorio especifico */
int	go_path(t_cmd *cmd, t_env **env)
{
	struct stat	info_f;

	(void)env;
	if (!exist_cwd())
		return (1);
	else
	{
		if (cmd->commands[1] == NULL)
			return (1);
		// Obtener información sobre el archivo
		if (stat(cmd->commands[1], &info_f) == -1)
		{
			ft_msgs(4, cmd);
			return (1);
		}
		if (!S_ISDIR(info_f.st_mode) || \
			!(info_f.st_mode & S_IRUSR) || !(info_f.st_mode & S_IXUSR))
		{
			ft_msgs(7, cmd);
			return (1);
		}
		if (chdir(cmd->commands[1]) == -1)
		{
			ft_msgs(4, cmd);
			return (1);
		}
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
	else if ((ft_strcmp(cmd->commands[1], " ") == 0) || (ft_strcmp(cmd->commands[1], " / ") == 0))
	{
		ft_msgs(4, cmd);
		return (1);
	}
	else
	{
		current_wd = getcwd(NULL, 0);
		go_path(cmd, env);
	}
	update_pwd(*env);
	update_oldpwd(*env, current_wd);
	return (0);
}
