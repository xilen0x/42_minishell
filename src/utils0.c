#include "minishell.h"

/*funcion temporal de inicializacion de estructura t_built*/
void	init(t_built *cmd, char *av[])
{
	cmd->echo = 0;
	cmd->cd = 0;
	cmd->pwd = 0;
	cmd->export = 0;
	cmd->unset = 0;
	cmd->env = 0;
	cmd->exit = 0;
	cmd->cmd1 = av[1];
	cmd->path = av[2];
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