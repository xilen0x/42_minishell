# include "minishell.h"

int	builtin_echo(t_cmd *cmd)
{
	int	i;
	int	print_newline;

	i = 1;
	print_newline = 1;
	if (size_arr2d(cmd->commands) == 1)
	{
		printf("\n");
		get_signal = 0;
		return (0);
	}
	if (ft_strcmp(cmd->commands[1], "-n") == 0)
	{
		print_newline = 0;
		i++;
	}
	while (cmd->commands[i])
	{
		printf("%s", cmd->commands[i]);
		if (cmd->commands[i + 1] && cmd->commands[i][0] != '\0')
			printf(" ");
		i++;
	}
	if (print_newline)
		printf("\n");
	get_signal = 0;
	return (0);
}
