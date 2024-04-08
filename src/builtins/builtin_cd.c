#include "minishell.h"

/*funcion continuacion de builtin_cd */
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

/*Funcion que cambia de directorio al home del usuario en el caso de 'cd'
o a una ruta absoluta o relativa*/
int	builtin_cd(t_cmd	*cmd, t_env env)
{

	if ((size_arr2d(cmd->command_and_arg)) == 1)// cd only
		go_home();
	else if (ca_strcmp(cmd->command_and_arg[1], "~") == 0)
		go_home();
	else//cd with relative or absolute path
	{
		if (search_command_path(*cmd->command_and_arg, &env) == 0)
		{
			if (chdir(cmd->command_and_arg[1]) != 0)
			{
				perror("chdir() error");
				return (1);
			}
		}
	}
	return (0);
}
