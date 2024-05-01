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
// int	get_paths(t_env *env)
// {
// 	int		i;
// 	int		index;
// 	int		exit_status;
// 	char	**full_path;

// 	i = 0;
// 	while (env)
// 	{
// 		if (ca_strcmp(env->key, "PATH") != 0)
// 			break ;
// 		i++;
// 		env = env->next;
// 	}
// 	while (env)
// 	{
// 		full_path = ft_split(env->val, ':');
// 		index = i;
// 		exit_status = 0;
// 		env = env->next;
// 	}
// 	return (exit_status);
// }

char	**get_paths(t_env *env)
{
	int i = 0;
	char **full_path = NULL;

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

/*
	while (env != NULL)
	{
		if (ca_strcmp(var_ent[0], env->key) == 0)
		{
			//env_delone(&env, env, &free); //y la elimina de ser así
			flag = 1;
			break ;
		}
		i++;
		env = env->next;
	}
*/

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

/*Funcion que ejecuta un comando dado(no builtin)*/
int	executor(t_env *env, t_cmd *cmd)
{
	//int		fd[2];
	pid_t	pid;
	t_exe	*exe;

	if (builtins(cmd, env))
	{
		exe = NULL;
		exe = (t_exe *)malloc(sizeof(t_exe));
		if (!exe)
			return (1);
		exe->paths = get_paths(env);
		exe->cmd_fullpath = NULL;
		search_command_path(cmd, exe);
		list_to_array(env, exe);
		printf("no soy builtin\n");
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		 if (execve(exe->cmd_fullpath, cmd->command_and_arg, exe->new_array) < 0)
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
	return(0);
}
