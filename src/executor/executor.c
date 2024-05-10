# include "minishell.h"

/*function that search by the 'PATH' word and split the content*/
char	**get_paths(t_env *env)
{
	int		i;
	char	**full_path;

	i = 0;
	full_path = NULL;
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
		{
			full_path = ft_split(env->val, ':');
			break ;
		}
		i++;
		env = env->next;
	}
	return (full_path);
}

/*funcion que crea el fullpath del comando y verifica si existe
para poder guardarlo o no*/
int	search_command_path(t_cmd *cmd, t_exe *exe)
{
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (exe->paths[i] != NULL)
	{
		cmd_path = ft_strjoin("/", cmd->commands[0]);
		full_path = ft_strjoin(exe->paths[i], cmd_path);
		free(cmd_path);
		if (full_path == NULL)
			return (-1);
		if (access(full_path, F_OK) == 0)
		{
			exe->cmd_fullpath = full_path;
			return (0);
		}
		free(full_path);
		i++;
	}
	return (1);
}

/*close fd 0 and 1*/
int	close_fd(t_exe	*exe)
{
	close(exe->fd[0]);
	close(exe->fd[1]);
	return (0);
}

/*execute commands in pipes*/
int	executor_core(t_cmd *cmd, t_exe	*exe, t_env **env)
{
	int		i;

	exe->fd_input = dup(STDIN_FILENO);
	exe->fd_output = dup(STDOUT_FILENO);
	i = 0;
	while (cmd)
	{
		if (pipe(exe->fd) == -1)
			error_exe(1);
		exe->pid[i] = fork();
		if (exe->pid[i] < 0)
			error_exe(2);
		else if (exe->pid[i] == 0)//proceso(s) hijo(s)
		{
			exe->paths = get_paths(*env);
			// ft_open_files(argv, &data);
			exe->cmd_fullpath = NULL;
			search_command_path(cmd, exe);
			list_to_array(*env, exe);
			if (cmd->next != NULL)
				dup2(exe->fd[1], STDOUT_FILENO);
			close_fd(exe);
			//redireccion aqui?
			if (execve(exe->cmd_fullpath, cmd->commands, exe->new_array) < 0)
				ft_msgs(0);
			exit(0);
		}
		dup2(exe->fd[0], STDIN_FILENO);
		close_fd(exe);
		i++;
		cmd = cmd->next;
	}
	int status;//reemplazar luego esto por lo de la funcion de exit_status
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

void	redirections(t_cmd *cmd, t_exe *exe)
{
	t_redir	*aux;

	if (cmd->next != NULL)
		dup2(exe->fd[1], STDOUT_FILENO);
	close_fd(exe);
	aux = cmd->redir;
	while (aux)
	{
		// if (dup_custom_redirections(exe, aux) == 1)
		// {
		// 	unlink_heredocs(commands->redirect);
		// 	if (out == FT_RETURN)
		// 		return (perror_return(data, 1, aux. ->file));
		// 	else
		// 		perror_exit(data, EXIT_FAILURE, temp->file);
		// }
		printf("teste\n");
		aux = aux->next;
	}
}

/*Funcion que ejecuta un comando dado o direcciona a builtin si es el caso*/
int	executor(t_env **env, t_cmd *cmd)
{	
	int		size_pipe;

	//signals here...soon
	size_pipe = cmd_size(cmd);
// //	redirections(cmd, exe);
	if (is_builtins(cmd) && (size_pipe == 1))
	{
		free(exe.pid);
		return (builtins(cmd, env));
	}
	else
		executor_core(cmd, &exe, env);
	free(exe.pid);
	return (0);
}
