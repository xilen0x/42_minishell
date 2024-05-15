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
	while (cmd)
	{
		if (pipe(exe->fd) == -1)// guarda en fd los dos file descriptors
			error_exe(1);
		exe->pid[i] = fork();//crea un proceso hijo, clon del padre
		if (exe->pid[i] < 0)
			error_exe(2);
		else if (exe->pid[i] == 0) // Si condicion se cumple, se ejecutará el proceso hijo
		{
			exe->paths = get_paths(*env);
			if (pre_redirections(cmd, exe) == 0)
			{
				exe->cmd_fullpath = NULL;
				search_command_path(cmd, exe);
				list_to_array(*env, exe);
				if (cmd->next != NULL)
					dup2(exe->fd[1], STDOUT_FILENO);
				close_fd(exe);
				if (execve(exe->cmd_fullpath, cmd->commands, exe->new_array) < 0)
					ft_msgs(0);
				exit(0);
			}
			exit(1);
		}
		dup2(exe->fd[0], STDIN_FILENO);
		close_fd(exe);
		i++;
		cmd = cmd->next;
	}
	return (0);
}


/*
		else if (aux->redir_type == HEREDOC_INPUT)
		{
			exe->fd_input = open(aux->filename, O_CREAT | O_RDWR, 0660);
			if (exe->fd_input == -1)
				return (1);
			if (dup2(exe->fd_input, STDOUT_FILENO) == -1)
				return (1);
			close(exe->fd_input);
		}
*/

/*execute commands in pipes - p1*/
int	executor(t_cmd *cmd, t_exe	*exe, t_env **env)
{
	int		i;

	exe->fd_input = dup(STDIN_FILENO);//almaceno el fd de stdin en fd_input y stdout en fd_output
	exe->fd_output = dup(STDOUT_FILENO);
	i = 0;
	executor_core(cmd, exe, env, i);
	int status;//reemplazar luego esto por lo del exit_status de joan
	dup2(exe->fd_input, STDIN_FILENO);
	dup2(exe->fd_output, STDOUT_FILENO);
	i = 0;
	while (i < exe->num_cmds)
	{
		waitpid(exe->pid[i], &status, 0);
		i++;
	}
	return (0);
}

/*Funcion que direcciona a builtin si es el caso o envia pipe a executor*/
int	pre_executor(t_env **env, t_cmd *cmd, t_exe *exe)
{
	unsigned int	size_pipe;
	t_redir			*aux;
	//signals here...soon
	aux = p_malloc(sizeof(t_redir));
	size_pipe = cmd_size(cmd);
	aux = cmd->redir;
	if (!exist_redirections(aux))//0: if NO hay redirecciones
	{
		if (is_builtins(cmd) && (size_pipe == 1))
		{
			free(exe->pid);
			return (builtins(cmd, env));
		}
		else
			executor(cmd, exe, env);
	}
	else//1: if Sí hay redirecciones
		executor(cmd, exe, env);
	free(exe->pid);
	return (0);
}
