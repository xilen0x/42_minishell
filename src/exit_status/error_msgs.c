/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:29:24 by castorga          #+#    #+#             */
/*   Updated: 2024/05/30 12:28:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	not_valid_identif(t_cmd *cmd, const char *prefix, size_t prefix_len)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_len);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, "not a valid identifier\n", 23);
}

int	print_syntax_error(const char *prefix, size_t prefix_len)
{
	write(2, prefix, prefix_len);
	write(2, ": ", 2);
	write(2, "syntax error\n", 13);
	return (1);
}

void	not_a_directory(t_cmd *cmd, const char *prefix, size_t prefix_len)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_len);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, "Not a directory\n", 16);
}

int	ft_msgs2(int n, t_cmd *cmd, const char	*prefix, size_t	prefix_len)
{
	if (n == 0)
		command_not_found(cmd, prefix, prefix_len);
	else if (n == 4)
		no_file_or_dir(cmd, prefix, prefix_len);
	else if (n == 5)
		not_valid_identif(cmd, prefix, prefix_len);
	else if (n == 6)
		print_syntax_error(prefix, prefix_len);
	else if (n == 7)
		not_a_directory(cmd, prefix, prefix_len);
	return (1);
}

int	ft_msgs(int n, t_cmd *cmd)
{
	const char	*prefix;
	size_t		prefix_len;

	prefix = "minishell: ";
	prefix_len = ft_strlen(prefix);
	if ((n == 0) || (n == 4) || (n == 5) || (n == 6) || (n == 7))
		ft_msgs2(n, cmd, prefix, prefix_len);
	else if (n == 8)
		write(2, "invalid option\n", 15);
	else if (n == 1)
		write(2, "minishell: cannot execute binary file\n", 38);
	else if (n == 2)
		write(2, "minishell: undefined_error\n", 27);
	else if (n == 3)
		write(2, "minishell: Permission denied\n", 29);
	else if (n == 9)
		write(2, "minishell: exit: too many arguments\n", 36);
	else if (n == 10)
		write(2, "Run minishell without arguments!\n", 33);
	set_exit_status(1);
	return (1);
}
