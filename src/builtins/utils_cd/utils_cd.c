/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:36:38 by castorga          #+#    #+#             */
/*   Updated: 2024/06/05 16:36:41 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* cd with no argument */
int	handle_no_argument(t_cmd *cmd)
{
	if (size_arr2d(cmd->commands) == 1)
		return (go_home());
	return (0);
}

/* handle the 'cd ~' */
int	handle_tilde(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], "~") == 0)
		return (go_home());
	return (0);
}

/* handle the 'cd -' */
int	handle_dash(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], "-") == 0)
	{
		set_old_pwd();
		return (1);
	}
	return (0);
}

/* handle the 'cd .' */
int	handle_dot(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], ".") == 0)
		return (1);
	return (0);
}

/* handle invalid path */
int	handle_invalid_path(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], " ") == 0 || \
		ft_strcmp(cmd->commands[1], " / ") == 0)
	{
		ft_msgs(4, cmd);
		return (1);
	}
	return (0);
}
