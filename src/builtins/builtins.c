#include "minishell.h"

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
//int	builtings(t_built	*cmd, char	**env, int ac)
int	builtins(t_built *cmd, t_env env, int ac, char *av[])
{
	(void)env;
	if (ca_strcmp(cmd->cmd1, "exit"))
	{
		//printf("testeeeee\n");
		builtin_exit(cmd, ac, av);
		return (0);
	}
	/*else if (ft_strcmp(token.value, "pwd") == 0)
	{
	 	builtin_pwd();
	}*/
	// else if (ft_strcmp(cmd->cmd1, "cd") == 0)
	// {
	// 	builtin_cd(cmd, ac);
	// 	return (0);
	// }
	// else if (ft_strcmp(cmd->cmd1, "echo") == 0)
	// {
	// 	builtin_echo(cmd, ac);
	// 	return (0);
	// }
	// else if (ft_strcmp(cmd->cmd1, "env") == 0)
	// {
	// 	builtin_env(env);
	// 	return (0);
	// }
	// else if (ft_strcmp(cmd->cmd1, "export") == 0)
	// {
	// 	builtin_export(env, ac);
	// 	return (0);
	// }
	else
	{
		printf("bash: %s: command not foundeee\n", cmd->cmd1);
	}
	return (0);
}
