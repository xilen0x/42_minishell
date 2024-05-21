#include "minishell.h"

/*Funcion que muestra mensaje de error y uso correcto*/
int	ft_msgs(int n, t_cmd *cmd)
{
	const char	*prefix;
	const char	*error_message;
	size_t		prefix_length;
	size_t		len_error_msg;
	size_t		len_cmd;

	prefix = "minishell: ";
	prefix_length = ft_strlen(prefix);
	len_cmd = ft_strlen(cmd->commands[0]);
	error_message = strerror(errno);
	len_error_msg = ft_strlen(error_message);
	if (n == 0)
	{
		write(2, prefix, prefix_length);
		write(2, cmd->commands[0], len_cmd);
		write(2, ": ", 2);
		write(2, "command not found", 17);
		write(2, "\n", 1);
		return (127);//aki voy
		/*
		>>>>minishell$ echoecho
minishell: echoecho: command not found
>>>>minishell$ $?
minishell: 0: command not found
		*/
	}
	else if (n == 1)
		write (2, "cannot execute binary file\n", 27);
	else if (n == 2)
	{
		write(2, prefix, prefix_length);
		write(2, cmd->commands[0], len_cmd);
		write(2, ": ", 2);
		write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
		write(2, ": ", 2);
		write(2, error_message, len_error_msg);
		write(2, "\n", 1);
	}
	else if (n == 3)
		write (2, "bash: outfile: Permission denied\n", 33);
	else if (n == 4)
	{
		write(2, error_message, len_error_msg);
		write(2, "\n", 1);
	}
	else if (n == 5)
		write (2, "not a valid identifier\n", 24);
	else if (n == 6)
		write (2, "invalid option\n", 15);
	else if (n == 10)
		write (2, "Run minishell without arguments!\n", 33);
	return (0);
}

/*Function that get the exit status number*/
/*int	get_exit_status(t_exe *exe)
{
	printf("%d: %s", exe->exit_stat, "command not found\n");
	return (0);
}*/

/*Function that set the exit status number*/
/*void	set_exit_status(int num, t_exe *exe)
{
	exe->exit_stat = num;
}*/