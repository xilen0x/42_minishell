# include "minishell.h"

int	ca_isnumber(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	builtin_exit(t_cmd *cmd)
{
	if ((size_arr2d(cmd->command_and_arg)) > 1)
	{
		if (ca_isnumber(cmd->command_and_arg[1]))
		{
			printf("exit\n");
			exit(ft_atoi(cmd->command_and_arg[1]));
		}
		else
		{
			printf("exit\n");
			//printf("%s: exit: %s: numeric argument required\n", av[0], cmd->path);
			exit(0);
		}
	}
	else
		printf("exit\n");
	return (0);
}
