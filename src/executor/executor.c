# include "minishell.h"

/* Close fd 0 and 1 if corresp.*/
int	close_fd(t_exe	*exe)
{
	if (exe->fd[0] != -1)
		close(exe->fd[0]);
	if (exe->fd[1] != -1)
		close(exe->fd[1]);
	return (0);
}

/*execute commands in pipes - p2.*/
int	executor_core(t_cmd *cmd, t_exe	*exe, t_env **env, int i)
{
	int		err_execve;

	while (cmd)
	{
		if (pipe(exe->fd) == -1) // guarda en fd los dos file descriptors
			error_exe(1);
		exe->pid[i] = fork();
		if (exe->pid[i] < 0)
			error_exe(2);
		else if (exe->pid[i] == 0) // Si condicion se cumple, se ejecutará el proceso hijo
		{
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
		dup2(exe->fd[0], STDIN_FILENO);
		close_fd(exe);
		i++;
		cmd = cmd->next;
	}
	return (0);
}

/*execute commands in pipes - p1*/
int	executor(t_cmd *cmd, t_exe	*exe, t_env **env)
{
	int	i;
	int	status;
	int	exit_status;

	exit_status = 0;
	exe->fd_input = dup(STDIN_FILENO);//almaceno los fd estandar
	exe->fd_output = dup(STDOUT_FILENO);
	i = 0;
	executor_core(cmd, exe, env, i);
	dup2(exe->fd_input, STDIN_FILENO);
	dup2(exe->fd_output, STDOUT_FILENO);
	i = 0;
	while (i < exe->num_cmds)
	{
		if (waitpid(exe->pid[i], &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
		if (WIFEXITED(status))
		{
			int child_exit_status = WEXITSTATUS(status);
			if (child_exit_status != 0)
				exit_status = child_exit_status; // se actualiza exit_status si el hijo no terminó exitosamente
		}
		i++;
	}
	g_get_signal = exit_status;
	return (0);
}

/*Funcion que direcciona a builtin si es el caso o envia pipe a executor*/
int	pre_executor(t_env **env, t_cmd *cmd, t_exe *exe)
{
	unsigned int	size_pipe;

	size_pipe = cmd_size(cmd);
	if (!exist_redirections(cmd))//--------------0: if NO hay redirecciones
	{
		if (is_builtins(cmd) && (size_pipe == 1))
		{
			free(exe->pid);
			return (builtins(cmd, env));
		}
		else
			executor(cmd, exe, env);
	}
	else//---------------------------------------1: if Sí hay redirecciones
	{
		if (cmd->commands == NULL)	
		{
			ft_msgs(6, cmd);
			// write(1, "no hay comando\n", 15);//aqui debe crear el archivo vacio
			return (1);
		}
		executor(cmd, exe, env);
	}
	free(exe->pid);
	return (0);
}
