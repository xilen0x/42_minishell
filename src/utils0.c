#include "minishell.h"

/*funcion temporal de inicializacion de estructura t_built*/
int	init(t_built *cmd, int ac, char *av[])
{
	//!!!queda pendiente implementar la opcion -n!!!
	(void)ac;
	// cmd->export = 0;
	// cmd->unset = 0;
	// cmd->env = 0;
	// cmd->exit = 0;
	// cmd->cd = av[1];
	cmd->cmd1 = av[1];
	cmd->path = av[2];
	// if (av[2])
	// {
	// 	if (ft_strcmp(av[2], "-n") == 0)
	// 	{
	// 		cmd->echo_n = av[2];
	// 		cmd->the_string = av[3];
	// 	}
	// 	else
	// 		cmd->the_string = av[2];
	// }
	return (0);
}



// void	print_env(char **env)
// {
// 	int	i = 0;

// 	while (env[i])
// 	{
// 		printf("%s\n", env[i]);
// 		i++;
// 	}
// }