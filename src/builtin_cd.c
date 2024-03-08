#include "minishell.h"

/*Funcion que cambia de directorio al home del usuario en el caso de 'cd'
o a una ruta absoluta o relativa*/
int	change_directory(t_built	*cmd, int ac)
{
	char	*home_dir;

	(void)cmd;
	if (ac == 2)//cambiar luego!!!
	{
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
		get_pwd();// solo para visualizar el pwd actual - borrar luego!!!
	}
	else//relative or absolute path
	{
		if (chdir(cmd->path) != 0)
		{
			perror("chdir() error");
			return (1);
		}
		get_pwd();// solo para visualizar el pwd actual - borrar luego!!!
	}
	return (0);
}
