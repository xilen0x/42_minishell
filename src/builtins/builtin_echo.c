# include "minishell.h"

void	print_without_quotes(char *str)
{
//	int	len;
//
////	len = ft_strlen(str);
//	if ((len >= 2 && str[0] == '"' && str[len - 1] == '"') || \
//	(len >= 2 && str[0] == '\'' && str[len - 1] == '\''))
//		printf("%.*s", len - 2, str + 1);
//	else
		printf("%s", str);
}

int	builtin_echo(t_cmd *cmd)
{
	int	i;
	int	print_newline;

	i = 1;
	print_newline = 1;
	if (size_arr2d(cmd->commands) == 1)
	{
		printf("\n");
		return (0);
	}
	// if ((ca_strchr(&cmd->commands[1][0], '-') == 1) && \
	// 			(ca_strchr(&cmd->commands[1][1], 'n') == 1))
	// {
	// 	print_newline = 0;
	// 	i++;
	// }
	if (ft_strcmp(cmd->commands[1], "-n") == 0)
	{
		print_newline = 0;
		i++;
	}
	while (cmd->commands[i])// != '\0' ???
	{
		// print_without_quotes(cmd->commands[i]);
		printf("%s", cmd->commands[i]);
		if (cmd->commands[i + 1])
			printf(" ");
		i++;
	}
	if (print_newline)
		printf("\n");
	return (0);
}
