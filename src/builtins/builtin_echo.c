# include "minishell.h"

int	builtin_echo_n(t_cmd	*cmd)
{
	int	i;

	i = 1;
	if (((size_arr2d(cmd->command_and_arg)) > 1) && (ca_strcmp(cmd->command_and_arg[1], "-n") == 0))
	{
		while (cmd->command_and_arg[i])
		{
			printf ("%s", cmd->command_and_arg[i]);
			i++;
		}
		return (0);
	}
	// else
	// {
	// 	while (cmd->command_and_arg[i])
	// 	{
	// 		printf ("%s\n", cmd->command_and_arg[i]);
	// 		i++;
	// 	}
	// }
	return (0);
}

int	builtin_echo(t_cmd	*cmd)
{
	int	i;

	i = 1;
	if ((size_arr2d(cmd->command_and_arg)) == 1)
		write (1, "\n", 1);
	else if (((size_arr2d(cmd->command_and_arg)) > 1) && (!(ca_strcmp(cmd->command_and_arg[1], "-n") == 0)))
	{
		while (cmd->command_and_arg[i])
		{
			printf ("%s\n", cmd->command_and_arg[i]);
			i++;
		}
		//write (1, "\n", 1);
		return (0);
	}
	// else
	// 	builtin_echo_n(cmd);
	return (0);
}
