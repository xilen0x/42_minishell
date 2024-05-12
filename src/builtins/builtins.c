#include "minishell.h"

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
int	builtins(t_cmd *cmd, t_env **env)
{
	if (ft_strcmp(*cmd->commands, "exit") == 0)
	{
		builtin_exit(cmd, *env);
		printf("\033[40m");//black
		exit (0);
	}
	else if ((ft_strcmp(*cmd->commands, "pwd") == 0) || \
		(ft_strcmp(*cmd->commands, "PWD") == 0))
		builtin_pwd(*env);
	else if (ft_strcmp(*cmd->commands, "cd") == 0)
		builtin_cd(cmd, env);
	else if (ft_strcmp(*cmd->commands, "env") == 0)
		builtin_env(cmd, *env);
	else if (ft_strcmp(*cmd->commands, "echo") == 0)
		builtin_echo(cmd);
	else if (ft_strcmp(*cmd->commands, "export") == 0)
		builtin_export(cmd, env);
	else if (ft_strcmp(*cmd->commands, "unset") == 0)
		builtin_unset(cmd, env);
	else
		return (0);
	return (1);
}

/*check if is builtin(1) or not(0)*/
int	is_builtins(t_cmd *cmd)
{
	if (ft_strcmp(*cmd->commands, "exit") == 0)
		return (1);
	else if ((ft_strcmp(*cmd->commands, "pwd") == 0) || \
		(ft_strcmp(*cmd->commands, "PWD") == 0))
		return (1);
	else if (ft_strcmp(*cmd->commands, "cd") == 0)
		return (1);
	else if (ft_strcmp(*cmd->commands, "env") == 0)
		return (1);
	else if (ft_strcmp(*cmd->commands, "echo") == 0)
		return (1);
	else if (ft_strcmp(*cmd->commands, "export") == 0)
		return (1);
	else if (ft_strcmp(*cmd->commands, "unset") == 0)
		return (1);
	else if (
		(ft_strcmp(*cmd->commands, "alias") == 0) ||
		(ft_strcmp(*cmd->commands, "source") == 0) ||
		(ft_strcmp(*cmd->commands, "trap") == 0) ||
		(ft_strcmp(*cmd->commands, "readonly") == 0) ||
		(ft_strcmp(*cmd->commands, "declare") == 0) ||
		(ft_strcmp(*cmd->commands, "set") == 0) ||
		(ft_strcmp(*cmd->commands, "eval") == 0) ||
		(ft_strcmp(*cmd->commands, "shift") == 0) ||
		(ft_strcmp(*cmd->commands, "fc") == 0) ||
		(ft_strcmp(*cmd->commands, "exec") == 0) ||
		(ft_strcmp(*cmd->commands, "jobs") == 0) ||
		(ft_strcmp(*cmd->commands, "history") == 0) ||
		(ft_strcmp(*cmd->commands, "bg") == 0) ||
		(ft_strcmp(*cmd->commands, "builtin") == 0) ||
		(ft_strcmp(*cmd->commands, "fg") == 0) ||
		(ft_strcmp(*cmd->commands, "type") == 0) ||
		(ft_strcmp(*cmd->commands, "ulimit") == 0) ||
		(ft_strcmp(*cmd->commands, "return") == 0))
		{
			printf("built-in was not included in the subject.!\n");
			return (1);
		}
	else
		return (0);
}
