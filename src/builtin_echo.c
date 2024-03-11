# include "minishell.h"

int	builtin_echo(t_built	*cmd, int ac)
{
	if (ac == 2)//cambiar luego******
		write (1, "\n", 1);
	else
	{
		// if (cmd->path == "-n")
		// 	printf ("%s", cmd->path);
		// else
			printf ("%s\n", cmd->path);
	}
	return (0);
}
