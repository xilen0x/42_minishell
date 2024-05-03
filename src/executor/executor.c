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

/*Funcion que ejecuta un comando dado(no builtin)*/
int	executor(t_env **env, t_cmd *cmd)
{
	t_exe	*exe;
	int		size_pipe;
	int		i;

	size_pipe = cmd_size(cmd);
	i = 0;
	if (is_builtins(cmd) && (size_pipe == 1))
		return (builtins(cmd, env));
	else
	{
		while (cmd)
		{
			//printf("tengo %d pipes\n", size_pipe);
			exe = NULL;
			exe = (t_exe *)malloc(sizeof(t_exe));
			if (!exe)
				return (1);
			exe->paths = get_paths(*env);
			exe->cmd_fullpath = NULL;
			search_command_path(cmd, exe);
			list_to_array(*env, exe);
			exe->pid[i] = fork();
			if (exe->pid < 0)
			{
				perror("Fork failed");
				exit(1);
			}
			else if (exe->pid == 0)
			{
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
	}


	return (0);
}
