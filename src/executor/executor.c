/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:29:12 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 18:29:15 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Close fd 0 and 1 if corresp.*/
int	close_fd(t_exe	*exe)
{
	if (exe->fd[0] != -1)
		close(exe->fd[0]);
	if (exe->fd[1] != -1)
		close(exe->fd[1]);
	return (0);
}

int	child_process(t_cmd *cmd, t_exe *exe, t_env **env)
{
	int		err_execve;

	set_signals(CHILD);
	exe->paths = get_paths(*env);
	if (pre_redirections(cmd, exe) == 0)
	{
		exe->cmd_fullpath = NULL;
		search_command_path(cmd, exe);
		list_to_array(*env, exe);
		if (cmd->next != NULL)
			dup2(exe->fd[1], STDOUT_FILENO);
		close_fd(exe);
		err_execve = execve(exe->cmd_fullpath, cmd->commands, exe->new_array);
		if (err_execve == -1)
		{
			ft_msgs(0, cmd);
			exit(127);
		}
	}
	exit(0);
}

/*execute commands in pipes - p2.*/
int	executor_core(t_cmd *cmd, t_exe	*exe, t_env **env, int *i)
{

	exe->fd_input = dup(STDIN_FILENO);
	exe->fd_output = dup(STDOUT_FILENO);
	while (cmd)
	{
		if (pipe(exe->fd) == -1) // guarda en fd los dos file descriptors
			error_exe(1);
		exe->pid[*i] = fork();
		if (exe->pid[*i] < 0)
			error_exe(2);
		else if (exe->pid[*i] == 0) // Si condicion se cumple, se ejecutará el proceso hijo
			child_process(cmd, exe, env);
		dup2(exe->fd[0], STDIN_FILENO);
		close_fd(exe);
		// *i++;
		cmd = cmd->next;
	}
	return (0);
}

/*execute commands in pipes - p1*/
int	executor(t_cmd *cmd, t_exe	*exe, t_env **env)
{
	int	i;
	int	status;
	int	child_exit_status;

	i = 0;
	executor_core(cmd, exe, env, &i);
	dup2(exe->fd_input, STDIN_FILENO);
	dup2(exe->fd_output, STDOUT_FILENO);
	i = 0;
	while (i < exe->num_cmds)
	{
		if (waitpid(exe->pid[i], &status, 0) == -1)
			return (1);
		if (WIFEXITED(status))
		{
			child_exit_status = WEXITSTATUS(status);
			if (child_exit_status != 0)
				status = child_exit_status;
		}
		i++;
	}
	g_get_signal = status;
	return (0);
}

/*Funcion que direcciona a builtin si es el caso o envia pipe a executor
0: if NO hay redirecciones
1: else Sí hay redirecciones*/
int	pre_executor(t_env **env, t_cmd *cmd, t_exe *exe, unsigned int size_pipe)
{
	if (!exist_redirections(cmd))
	{
		if (is_builtins(cmd) && (size_pipe == 1))
		{
			free(exe->pid);
			return (builtins(cmd, *exe, env));
		}
		if (no_path_env(cmd, *exe, *env))
			return (1);
		else
			executor(cmd, exe, env);
	}
	else
	{
		if (cmd->commands == NULL)
		{
			ft_msgs(6, cmd);
			return (1);
		}
		executor(cmd, exe, env);
	}
	free(exe->pid);
	return (0);
}
