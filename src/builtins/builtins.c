#include "minishell.h"

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
//int	builtings(t_built	*cmd, char	**env, int ac)
int	builtins(t_cmd *cmd, char *av[], t_shell *shell)
{
	/*if (ca_strcmp(*cmd->command_and_arg, "$?") == 0)//implementar al final de todas las buildins
	{
		exit_status();
		return (0);
	}
	else*/
	if (ca_strcmp(*cmd->command_and_arg, "exit") == 0)
	{
		builtin_exit(cmd, av);
		printf("\033[40m");//black
		exit (0);
	}
	else if ((ca_strcmp(*cmd->command_and_arg, "pwd") == 0) || (ca_strcmp(*cmd->command_and_arg, "PWD") == 0))
	{
		builtin_pwd();
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "cd") == 0)
	{
		builtin_cd(cmd, shell);
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "env") == 0)
	{
		builtin_env(cmd, shell->link_env);
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "echo") == 0)
	{
		builtin_echo(cmd);
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "export") == 0)
	{
		builtin_export(cmd, shell->link_env);
		return (0);
	}
	else if (ca_strcmp(*cmd->command_and_arg, "unset") == 0)
	{
		builtin_unset(cmd, shell->link_env);
		return (0);
	}
	else
		//ft_msgs(6);
		return (1);
	return (0);
}
