#include "minishell.h"

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
//int	builtings(t_built	*cmd, char	**env, int ac)
int	builtins(t_cmd *cmd, t_env *env)
{
	// if (ca_strcmp(*cmd->command_and_arg, "$?") == 0)//este if se irá(se tratará en expansor)
	// {
	// 	get_exit_status();
	// 	return (0);
	// }
	// else 
	if (ca_strcmp(*cmd->command_and_arg, "exit") == 0)
	{
		builtin_exit(cmd);
		printf("\033[40m");//black
		exit (0);
	}
	else if ((ca_strcmp(*cmd->command_and_arg, "pwd") == 0) || (ca_strcmp(*cmd->command_and_arg, "PWD") == 0))
		builtin_pwd(env);
	else if (ca_strcmp(*cmd->command_and_arg, "cd") == 0)
		builtin_cd(cmd, env);
	else if (ca_strcmp(*cmd->command_and_arg, "env") == 0)
		builtin_env(cmd, env);
	else if (ca_strcmp(*cmd->command_and_arg, "echo") == 0)
		builtin_echo(cmd);
	else if (ca_strcmp(*cmd->command_and_arg, "export") == 0)
		builtin_export(cmd, env);
	else if (ca_strcmp(*cmd->command_and_arg, "unset") == 0)
		builtin_unset(cmd, env);
	else
	{
		ft_msgs(4);
		return (1);
	}
	return (0);
	// exit (0);
}
