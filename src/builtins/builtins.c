#include "minishell.h"

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
int	builtins(t_cmd *cmd, t_env **env)
{
	if (ft_strcmp(*cmd->command_and_arg, "exit") == 0)
	{
		builtin_exit(cmd, *env);
		printf("\033[40m");//black
		exit (0);
	}
	else if ((ft_strcmp(*cmd->command_and_arg, "pwd") == 0) || \
		(ft_strcmp(*cmd->command_and_arg, "PWD") == 0))
		builtin_pwd(*env);
	else if (ft_strcmp(*cmd->command_and_arg, "cd") == 0)
		builtin_cd(cmd, env);
	else if (ft_strcmp(*cmd->command_and_arg, "env") == 0)
		builtin_env(cmd, *env);
	else if (ft_strcmp(*cmd->command_and_arg, "echo") == 0)
		builtin_echo(cmd);
	else if (ft_strcmp(*cmd->command_and_arg, "export") == 0)
		builtin_export(cmd, env);
	else if (ft_strcmp(*cmd->command_and_arg, "unset") == 0)
		builtin_unset(cmd, env);
	else
		return (0);
	return (1);
}

/*check if is builtin(1) or not(0)*/
int	is_builtins(t_cmd *cmd)
{
	if (ft_strcmp(*cmd->command_and_arg, "exit") == 0)
		return (1);
	else if ((ft_strcmp(*cmd->command_and_arg, "pwd") == 0) || \
		(ft_strcmp(*cmd->command_and_arg, "PWD") == 0))
		return (1);
	else if (ft_strcmp(*cmd->command_and_arg, "cd") == 0)
		return (1);
	else if (ft_strcmp(*cmd->command_and_arg, "env") == 0)
		return (1);
	else if (ft_strcmp(*cmd->command_and_arg, "echo") == 0)
		return (1);
	else if (ft_strcmp(*cmd->command_and_arg, "export") == 0)
		return (1);
	else if (ft_strcmp(*cmd->command_and_arg, "unset") == 0)
		return (1);
	else if (
		(ft_strcmp(*cmd->command_and_arg, "alias") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "source") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "trap") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "readonly") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "declare") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "set") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "eval") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "shift") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "fc") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "exec") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "jobs") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "history") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "bg") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "builtin") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "fg") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "type") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "ulimit") == 0) ||
		(ft_strcmp(*cmd->command_and_arg, "return") == 0))
		{
			printf("built-in was not included in the subject.!\n");
			return (1);
		}
	else
		return (0);
}
