#include "minishell.h"

/*funcion que cambia al directorio home del usuario */
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

/*funcion que cambia a un directorio determinado */
static int	go_root(void)
{
	if (chdir("/") != 0)
	{
		perror("chdir() error");
		return (1);
	}
	return (0);
}

/*Funcion que cambia de directorio al home del usuario en el caso de 'cd'
o a una ruta absoluta o relativa*/
int	builtin_cd(t_cmd	*cmd, t_shell *shell)
{
	(void)shell;

	if ((size_arr2d(cmd->command_and_arg)) == 1)// cd only
		go_home();
	else if (ca_strcmp(cmd->command_and_arg[1], "~") == 0)
		go_home();
	else if (ca_strcmp(cmd->command_and_arg[1], "/") == 0)
		go_root();
	else if (ca_strcmp(cmd->command_and_arg[1], ".") == 0)
	{
		printf(". detectado\n");
	}
	else if (ca_strcmp(cmd->command_and_arg[1], "..") == 0)
	{
		printf(".. detectado\n");
	}
	// {
		// if (search_command_path(shell) == 0)
		// {
		// 	if (chdir(cmd->command_and_arg[1]) != 0)
		// 	{
		// 		perror("chdir() error");
		// 		return (1);
		// 	}
		// }
	// }
	return (0);
}
