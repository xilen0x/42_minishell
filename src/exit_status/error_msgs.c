/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:24 by castorga          #+#    #+#             */
/*   Updated: 2024/05/28 15:29:26 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_command_not_found(t_cmd *cmd, const char *prefix, size_t prefix_length)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_length);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
	g_get_signal = 127;
}

void	print_cannot_execute_binary_file(t_cmd *cmd, const char *prefix, size_t prefix_length)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_length);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, "command not found", 17);
	write(2, "\n", 1);
	write(2, "cannot execute binary file\n", 27);
}

void	print_undefined_error(t_cmd *cmd, const char *prefix, size_t prefix_length)
{
	const char	*error_message;
	size_t		len_error_msg;
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	error_message = strerror(errno);
	len_error_msg = ft_strlen(error_message);
	write(2, prefix, prefix_length);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, error_message, len_error_msg);
	write(2, "\n", 1);
}

void	print_permission_denied(t_cmd *cmd, const char *prefix, size_t prefix_length)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_length);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, "Permission denied\n", 18);
}

void	print_no_such_file_or_directory(t_cmd *cmd, const char *prefix, size_t prefix_length)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_length);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, "No such file or directory", 25);
	write(2, "\n", 1);
}

void	print_not_valid_identifier(t_cmd *cmd, const char *prefix, size_t prefix_length)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_length);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, "not a valid identifier\n", 23);
}

void	print_syntax_error(const char *prefix, size_t prefix_length)
{
	write(2, prefix, prefix_length);
	write(2, ": ", 2);
	write(2, "syntax error\n", 13);
}

void	print_not_a_directory(t_cmd *cmd, const char *prefix, size_t prefix_length)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_length);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, "Not a directory\n", 16);
}

void	print_run_without_arguments(void)
{
	write(2, "Run minishell without arguments!\n", 33);
}

int	ft_msgs(int n, t_cmd *cmd)
{
	const char	*prefix;
	size_t		prefix_length;

	prefix = "minishell: ";
	prefix_length = ft_strlen(prefix);
	if (n == 0)
		print_command_not_found(cmd, prefix, prefix_length);
	else if (n == 1)
		print_cannot_execute_binary_file(cmd, prefix, prefix_length);//no utilizado
	else if (n == 2)
		print_undefined_error(cmd, prefix, prefix_length);//no utilizado
	else if (n == 3)
		print_permission_denied(cmd, prefix, prefix_length);//no utilizado
	else if (n == 4)
		print_no_such_file_or_directory(cmd, prefix, prefix_length);
	else if (n == 5)
		print_not_valid_identifier(cmd, prefix, prefix_length);
	else if (n == 6) 
		print_syntax_error(prefix, prefix_length);
	else if (n == 7)
		print_not_a_directory(cmd, prefix, prefix_length);
	else if (n == 8)
		write(2, "invalid option\n", 15);//no utilizado
	else if (n == 10)
		print_run_without_arguments();
	g_get_signal = 1;
	return (1);
}
