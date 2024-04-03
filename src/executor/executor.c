# include "minishell.h"

/*int init_momentaneo(char *av[], t_env *data)
{
	(void)av;
	char *comando[] = {"ls", "-l", "-h", "-a", NULL};
	//char *comando[] = {"cat", "teste", NULL};
	//char *comando[] = {"mkdir", "carpeta", NULL};
	//char *comando[] = {"top", NULL};
	//char *comando[] = {"cd", NULL};

	int count = 0;
	while (comando[count] != NULL)
		count++;
	data->to_cmd = malloc(sizeof(t_cmd));
	if (data->to_cmd == NULL)
		return (-1);
	// Inicializar puntero temporal para iterar
	t_cmd *current_cmd = data->to_cmd;
	current_cmd->cmd_arg = malloc((count + 1) * sizeof(char *));
	if (current_cmd->cmd_arg == NULL)
	{
		free(data->to_cmd);
		return (-1);
	}
	// Copiar los elementos de comando en cmd_arg
    int i = 0;
	while (comando[i] != NULL) {
		current_cmd->cmd_arg[i] = comando[i];
		i++;
	}
	current_cmd->cmd_arg[count] = NULL; // final del array de argumentos
	current_cmd->pipe_test = comando[0];
	// Establecer next a NULL ya que solo hay un elemento en este ejemplo
	current_cmd->next = NULL;
	return (0);
}*/

/*Función que obtiene y guarda los envp path*/
void	ft_get_paths(char **envp, t_env *data)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	data->paths = ft_split(&envp[i][5], ':');
}

/*Funcion que abre los archivos de entrada y salida(from PIPEX)*/
/*void	ft_open_files(char **argv, t_env *data)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
		ft_errors(2);
	data->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (data->outfile_fd == -1)
		ft_errors(3);
}*/

/*funcion que crea el fullpath del comando y verifica si existe
para poder guardarlo o no*/
static int	search_command_path(char **cmd, t_env *data)
{
	char	*cmd_path;
	char	*full_path;
	int		i;

	i = 0;
	while (data->paths[i])
	{
		cmd_path = ft_strjoin("/", *cmd);
		full_path = ft_strjoin(data->paths[i], cmd_path);
		free(cmd_path);
		if (access(full_path, F_OK) == 0)
		{
			data->cmd_fullpath = full_path;
			return (0);
		}
		i++;
	}
	return (1);
}

/*Función puente que envia los comandos 1 a search_command_path */
int	search_cmds(t_env *data)
{
	if (search_command_path(data->to_cmd->command_and_arg, data) != 0)//Exception has occurred: Exception - EXC_BAD_ACCESS (code=1, address=0x0)
	{
		ft_errors(4);
		return (1);
	}
	/*if (search_command_path2(data->args_2[0], data) == 1)
	{
		ft_errors(4);
		return (1);
	}*/
	return (0);
}

int	executor(t_env *data)
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
		if (execve(data->cmd_fullpath, data->to_cmd->command_and_arg, data->env_cpy) < 0)//Se ejecuta el primer comando
		{
			perror(data->cmd_fullpath);
			exit(1);
		}
		// close(fd[1]);
		return(0);
	}
	else
	{
		wait(NULL);
		//execve(data->cmd2_fullpath, data->args_2, NULL);
		//close(fd[0]);
		return(0);
	}
	return(0);
}
