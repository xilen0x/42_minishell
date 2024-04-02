#include "minishell.h"

int	is_builtin(t_built *cmd, int ac, char *av[], t_env env)
{
	init(cmd, ac, av);
	if ((ca_strcmp(cmd->cmd1, "exit") == 0) || \
		(ca_strcmp(cmd->cmd1, "pwd") == 0) || \
		(ca_strcmp(cmd->cmd1, "cd") == 0) || \
		(ca_strcmp(cmd->cmd1, "echo") == 0) || \
		(ca_strcmp(cmd->cmd1, "env") == 0) || \
		(ca_strcmp(cmd->cmd1, "export") == 0) || \
		(ca_strcmp(cmd->cmd1, "unset") == 0))
		{
			builtins(cmd, ac, av, env);
			return (1);
		}
	return (0);
}

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
//int	builtings(t_built	*cmd, char	**env, int ac)
int	builtins(t_built *cmd, int ac, char *av[], t_env env)
{
	if (ca_strcmp(cmd->cmd1, "exit") == 0)
	{
		//printf("exit_teste\n");
		builtin_exit(cmd, ac, av);
		exit (0);
	}
	else if (ca_strcmp(cmd->cmd1, "pwd") == 0)
	{
		//printf("pwd_teste\n");
	 	builtin_pwd();
	}
	else if (ca_strcmp(cmd->cmd1, "cd") == 0)
	{
		builtin_cd(cmd, ac);
		return (0);
	}
	else if (ca_strcmp(cmd->cmd1, "echo") == 0)
	{
		builtin_echo(cmd, ac);
		return (0);
	}
	else if (ca_strcmp(cmd->cmd1, "env") == 0)
	{
		builtin_env(env);
		return (0);
	}
	else if (ca_strcmp(cmd->cmd1, "export") == 0)
	{
		builtin_export(cmd, env, ac);
		return (0);
	}
	else if (ca_strcmp(cmd->cmd1, "unset") == 0)
	{
		builtin_unset(cmd, env, ac);
		return (0);
	}
	else
	{
		printf("bash: %s: command not foundeee\n", cmd->cmd1);
	}
	return (0);
}
