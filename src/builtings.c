#include "minishell.h"

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
//int	builtings(t_built	*cmd, t_env	env, int ac)
int	builtings(t_built	*cmd, char	**env, int ac)
{
	int		i;

	(void)env;
	i = 0;
	if (ft_strcmp(cmd->cmd1, "pwd") == 0)
		get_pwd();
	else if (ft_strcmp(cmd->cmd1, "cd") == 0)
	{
		change_directory(cmd, ac);
		return (0);
	}
	// else if (ft_strcmp(cmd->cmd1, "echo") == 0)
	// {
	// 	printf("echo\n");
	// 	return (0);
	// }
	else
	{
		printf("no soy un comando\n");
	}
	return (0);
}
