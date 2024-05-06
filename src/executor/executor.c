# include "minishell.h"



char	**get_paths(t_env *env)
{
	int		i;
	char	**full_path;

	i = 0;
	full_path = NULL;
	while (env)
	{
		if (ca_strcmp(env->key, "PATH") == 0)
		{
			//*index = i;
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
		cmd_path = ft_strjoin("/", cmd->command_and_arg[0]);
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

int	executor_core(t_cmd *cmd, t_exe	*exe, t_env **env)
{
	int		i;
	// pid_t	pid;

	i = 0;
	exe = NULL;
	exe = (t_exe *)malloc(sizeof(t_exe));
	if (!exe)
		return (1);
	while (cmd)
	{
		//printf("tengo %d pipes\n", size_pipe);
		exe->paths = get_paths(*env);
		exe->cmd_fullpath = NULL;
		search_command_path(cmd, exe);
		list_to_array(*env, exe);
		if (pipe(exe->fd) == -1)
			error_exe(1);
		exe->pid[i] = fork();
		if (exe->pid[i] < 0)
			error_exe(2);
		else if (exe->pid == 0)
		{
		//dup2(data->infile_fd, STDIN_FILENO);//Redirigir la entrada estándar al archivo de entrada
		// close(fd[0]);//Se cierra el descriptor de lectura del pipe (fd[0]) ya que no se utilizará en este proceso.
		// dup2(fd[1], STDOUT_FILENO);//Se redirige la salida estándar al fd[1] para que la salida del primer comando vaya al pipe.
			dup2(exe->fd_input, STDIN_FILENO);//aki voy!!!!!!
			close(exe->fd[0]);
			dup2(exe->fd[1], STDOUT_FILENO);
			if (execve(exe->cmd_fullpath, &cmd->command_and_arg[i], exe->new_array) < 0)
			{
				perror(exe->cmd_fullpath);
				exit(1);
			}
			//close(fd[1]);
			exit(0);
		}
		else
		{
			wait(NULL);
			//execve(env->cmd2_fullpath, env->args_2, NULL);
			//close(fd[0]);
			return(0);
		}
		//size_pipe--;
		i++;
		cmd = cmd->next;
	}
	return (0);
}


/*Funcion que ejecuta un comando dado(no builtin)*/
int	executor(t_env **env, t_cmd *cmd)
{
	t_exe	*exe;
	int		size_pipe;

	exe = NULL;
	size_pipe = cmd_size(cmd);
	if (init_exe(exe, cmd) == 1)
		return (1);
	if (is_builtins(cmd) && (size_pipe == 1))
		return (builtins(cmd, env));
	else
		executor_core(cmd, exe, env);
	return (0);
}
