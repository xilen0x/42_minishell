#include "minishell.h"

/*Funcion que muestra mensaje de error y uso correcto*/
int	ft_msgs(int n)
{
	if (n == 0)
		write (2, "minishell: command not found!\n", 30);
	else if (n == 1)
		write (2, "cannot execute binary file\n", 27);
	else if (n == 2)
		write (2, "No such file or directory\n", 26);
	else if (n == 3)
		write (2, "bash: outfile: Permission denied\n", 33);
	else if (n == 4)
		write (2, "...\n", 4);
	else if (n == 5)
		write (2, "not a valid identifier\n", 24);
	else if (n == 6)
		write (2, "invalid option\n", 15);
	else if (n == 10)
		write (2, "Run minishell without arguments!\n", 33);
	return (0);
}

/*Function that get the exit status number*/
/*int	get_exit_status(t_exe *exe)
{
	printf("%d: %s", exe->exit_stat, "command not found\n");
	return (0);
}*/

/*Function that set the exit status number*/
/*void	set_exit_status(int num, t_exe *exe)
{
	exe->exit_stat = num;
}*/