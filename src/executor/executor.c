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
		if (ca_strcmp(env->key, "PATH") == 0)
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
		exe->paths = get_paths(*env);
		exe->cmd_fullpath = NULL;
		search_command_path(cmd, exe);
		list_to_array(*env, exe);
		if (pipe(exe->fd) == -1)
			error_exe(1);
		exe->pid[i] = fork();
		if (exe->pid[i] < 0)
			error_exe(2);
		else if (exe->pid[i] == 0)
		{
			if (cmd->next != NULL)
				dup2(exe->fd[1], STDOUT_FILENO);
			//redireccion aqui?
			close_fd(exe);
			if (execve(exe->cmd_fullpath, cmd->command_and_arg, exe->new_array) < 0)
			{
				perror(exe->cmd_fullpath);
				exit(1);
			}
			printf("proceso hijo\n");
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


/*Funcion que ejecuta un comando dado(no builtin)*/
int	executor(t_env **env, t_cmd *cmd)
{
	t_exe	*exe;
	int		size_pipe;

	exe = NULL;
	exe = malloc(sizeof(t_exe));
	if (!exe)
		return (1);
	size_pipe = cmd_size(cmd);
	if (init_exe(exe, cmd) == 1)
		return (1);
	if (is_builtins(cmd) && (size_pipe == 1))
		return (builtins(cmd, env));
	else
		executor_core(cmd, exe, env);
	return (0);
}
