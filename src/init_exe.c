/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:45:03 by castorga          #+#    #+#             */
/*   Updated: 2024/05/30 15:45:06 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exe_free(t_exe *exe)
{
	if (exe->new_array)
		free_arr2d(exe->new_array);
	if (exe->paths)
		free_arr2d(exe->paths);
	if (exe->cmd_fullpath)
		free(exe->cmd_fullpath);
}

//Sets to 0 or NULL all variables from a 't_exe' struct
void	init_exe(t_exe *exe, t_cmd *cmd)
{
	exe->paths = NULL;
	exe->cmd_fullpath = NULL;
	exe->new_array = NULL;
	exe->num_cmds = cmd_size(cmd);
	exe->pid = p_malloc(sizeof(pid_t) * exe->num_cmds);
	exe->fd_input = 0;
	exe->fd_output = 0;
	exe->fd[0] = -1;
	exe->fd[1] = -1;
	exe->dup_stdin = 0;
	exe->dup_stdout = 0;
}
