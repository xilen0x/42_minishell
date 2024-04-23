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

/*cambia al directorio raiz */
static int	go_root(void)
{
	if (chdir("/") != 0)
	{
		perror("chdir() error");
		return (1);
	}
	return (0);
}

/*cambia al directorio padre */
static int	go_parent(void)
{
	if (chdir("..") != 0)
	{
		perror("chdir() error");
		return (1);
	}
	return (0);
}

/*cambia a un directorio especifico */
static int	go_path(t_shell *shell)
{
	if (chdir(shell->link_cmd->command_and_arg[1]) != 0)
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
	shell->link_cmd = cmd;
	if ((size_arr2d(cmd->command_and_arg)) == 1)// cd only
		go_home();
	else if (ca_strcmp(cmd->command_and_arg[1], "~") == 0)
		go_home();
	else if (ca_strcmp(cmd->command_and_arg[1], "/") == 0)
		go_root();
	else if (ca_strcmp(cmd->command_and_arg[1], ".") == 0)
		return (0);
	else if ((ca_strcmp(cmd->command_and_arg[1], ".") && \
			(ft_isalpha(cmd->command_and_arg[1][1]) == 1)))
		go_path(shell);
	else if (ca_strcmp(cmd->command_and_arg[1], "..") == 0)
		go_parent();
	else if (ft_isalpha(cmd->command_and_arg[1][0]))
		go_path(shell);
	return (0);
}
