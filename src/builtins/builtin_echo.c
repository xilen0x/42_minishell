# include "minishell.h"

void	print_without_quotes(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 2 && str[0] == '"' && str[len - 1] == '"')
		printf("%.*s", len - 2, str + 1);
	else
		printf("%s", str);
}

int	builtin_echo(t_cmd *cmd)
{
	int	i;
	int	print_newline;

	i = 1;
	print_newline = 1;
	if (size_arr2d(cmd->command_and_arg) == 1)
	{
		printf("\n");
		return (0);
	}
	else if (ca_strcmp(cmd->command_and_arg[1], "-n") == 0)
	{
		print_newline = 0;
		i++;
	}
	while (cmd->command_and_arg[i])
	{
		print_without_quotes(cmd->command_and_arg[i]);
		if (cmd->command_and_arg[i + 1])
			printf(" ");
		i++;
	}
	if (print_newline)
		printf("\n");
	return (0);
}
