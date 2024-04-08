# include "minishell.h"

/*Función que obtiene y guarda los envp path*/
void	ft_get_paths(char **envp, t_env *env)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	env->paths = ft_split(&envp[i][5], ':');
}

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

/*funcion que crea el fullpath del comando y verifica si existe
para poder guardarlo o no*/
int	search_command_path(char *cmd, t_env *env)
{
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (env->paths[i])
	{
		cmd_path = ft_strjoin("/", cmd);
		full_path = ft_strjoin(env->paths[i], cmd_path);
		free(cmd_path);
		if (access(full_path, F_OK) == 0)
		{
			env->cmd_fullpath = full_path;
			return (0);
		}
		i++;
	}
	return (1);
}

/*Funcion que ejecuta un comando dado(no builtin)*/
int	executor(t_env *env, t_cmd cmd)
{
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
		if (execve(env->cmd_fullpath, cmd.command_and_arg, env->env_cpy) < 0)
		{
			perror(env->cmd_fullpath);
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
	return(0);
}
