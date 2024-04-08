#include "minishell.h"

/*int	is_builtin(t_built *cmd, int ac, char *av[], t_env env)
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
}*/

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
//int	builtings(t_built	*cmd, char	**env, int ac)
int	builtins(t_cmd *cmd, int ac, char *av[], t_env env)
{
	(void)env;
	/*if (ca_strcmp(*cmd->command_and_arg, "$?") == 0)//implementar al final de todas las buildins
	{
		exit_status();
		return (0);
	}
	else*/
	if (ca_strcmp(*cmd->command_and_arg, "exit") == 0)
	{
		builtin_exit(cmd, ac, av);
		exit (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "pwd") == 0)
	{
		builtin_pwd();
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "cd") == 0)
	{
		builtin_cd(cmd, env);
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "env") == 0)
	{
		builtin_env(env);
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "echo") == 0)
	{
		builtin_echo(cmd);
		return (0);
	}
	/*else if (ca_strcmp(cmd->cmd1, "export") == 0)
	{
		builtin_export(cmd, env, ac);
		return (0);
	}
	else if (ca_strcmp(cmd->cmd1, "unset") == 0)
	{
		builtin_unset(cmd, env, ac);
		return (0);
	}*/
	else
		return (1);
	return (0);
}
