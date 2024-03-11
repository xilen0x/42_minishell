# include "minishell.h"

int	ft_echo(t_built	*cmd, int ac)
{
	//char	*home_dir;

	(void)cmd;
	if (ac == 2)//cambiar luego******
		write (1, "\n", 1);
	else
	{
		printf("%s\n",cmd->path);
	}
	return (0);
}
