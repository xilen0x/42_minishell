#include "minishell.h"

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
int	builtins(t_cmd *cmd, t_env **env)
{
	if (ca_strcmp(*cmd->command_and_arg, "exit") == 0)
	{
		builtin_exit(cmd, *env);
		printf("\033[40m");//black
		exit (0);
	}
	else if ((ca_strcmp(*cmd->command_and_arg, "pwd") == 0) || \
		(ca_strcmp(*cmd->command_and_arg, "PWD") == 0))
		builtin_pwd(*env);
	else if (ca_strcmp(*cmd->command_and_arg, "cd") == 0)
		builtin_cd(cmd, env);
	else if (ca_strcmp(*cmd->command_and_arg, "env") == 0)
		builtin_env(cmd, *env);
	else if (ca_strcmp(*cmd->command_and_arg, "echo") == 0)
		builtin_echo(cmd);
	else if (ca_strcmp(*cmd->command_and_arg, "export") == 0)
		builtin_export(cmd, env);
	else if (ca_strcmp(*cmd->command_and_arg, "unset") == 0)
		builtin_unset(cmd, env);
	else
		return (0);
	return (1);
}

/*check if is builtin(1) or not(0)*/
int	is_builtins(t_cmd *cmd)
{
	if (ca_strcmp(*cmd->command_and_arg, "exit") == 0)
		return (1);
	else if ((ca_strcmp(*cmd->command_and_arg, "pwd") == 0) || \
		(ca_strcmp(*cmd->command_and_arg, "PWD") == 0))
		return (1);
	else if (ca_strcmp(*cmd->command_and_arg, "cd") == 0)
		return (1);
	else if (ca_strcmp(*cmd->command_and_arg, "env") == 0)
		return (1);
	else if (ca_strcmp(*cmd->command_and_arg, "echo") == 0)
		return (1);
	else if (ca_strcmp(*cmd->command_and_arg, "export") == 0)
		return (1);
	else if (ca_strcmp(*cmd->command_and_arg, "unset") == 0)
		return (1);
	else
		return (0);
}
