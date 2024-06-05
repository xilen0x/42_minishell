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

void	command_not_found(t_cmd *cmd, const char *prefix, size_t prefix_len)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_len);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
	set_exit_status(127);
}

void	no_file_or_dir(t_cmd *cmd, const char *prefix, size_t prefix_len)
{
	size_t		len_cmd;

	len_cmd = ft_strlen(cmd->commands[0]);
	write(2, prefix, prefix_len);
	write(2, cmd->commands[0], len_cmd);
	write(2, ": ", 2);
	write(2, cmd->commands[1], ft_strlen(cmd->commands[1]));
	write(2, ": ", 2);
	write(2, "No such file or directory", 25);
	write(2, "\n", 1);
}
