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

int	builtin_exit(t_built *cmd, t_lst token, char *av[])
{
	(void)token;
	if (cmd->path)
	{
		if (ca_isnumber(cmd->path))
		{
			printf("exit\n");
			exit(ft_atoi(cmd->path));
		}
		else
		{
			printf("exit\n");
			printf("%s: exit: %s: numeric argument required\n", av[0], cmd->path);
			exit(255);
		}
	}
	return (0);
}
