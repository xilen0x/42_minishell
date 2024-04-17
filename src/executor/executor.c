# include "minishell.h"

/*Funcion que abre los archivos de entrada y salida(from PIPEX)*/
/*void	ft_open_files(char **argv, t_env *env)
{
	env->infile_fd = open(argv[1], O_RDONLY);
	if (env->infile_fd == -1)
		ft_errors(2);
	env->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (env->outfile_fd == -1)
		ft_errors(3);
}*/

/*Función que obtiene y guarda los envp path*/
t_exe	*get_paths(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell != NULL)
	{
		if (ca_strcmp(shell->link_env->key, "PATH") == 0)
		{
			shell->link_exe->paths = ft_split(shell->link_env->val, ':');
		}
		shell->link_env = shell->link_env->next;
	}
	return (shell->link_exe);
}

/*funcion que crea el fullpath del comando y verifica si existe
para poder guardarlo o no*/
int	search_command_path(t_shell *shell)
{
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (shell->link_exe->paths[i])
	{
		// cmd_path = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin("/", *shell->link_cmd->command_and_arg);
		// full_path = ft_strjoin(exe->paths[i], cmd_path);
		full_path = ft_strjoin(shell->link_exe->paths[i], cmd_path);
		free(cmd_path);
		if (access(full_path, F_OK) == 0)
		{
			// exe->cmd_fullpath = full_path;
			shell->link_exe->cmd_fullpath = full_path;
			return (0);
		}
		i++;
	}
	return (1);
}

/*Funcion que ejecuta un comando dado(no builtin)*/
int	executor(t_env *env, t_cmd cmd, t_exe *exe)
{
	(void)env;
	(void)cmd;
	(void)exe;
	//int		fd[2];
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		// if (execve(exe->cmd_fullpath, cmd.command_and_arg, env->env_cpy) < 0)//aqui debo pasarle el env como un array
		// {
		// 	perror(exe->cmd_fullpath);
		// 	exit(1);
		// }
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
	return(0);
}
