#include "minishell.h"

/*Función que obtiene y guarda los envp path*/
void	ft_get_paths(char **envp, t_comm *comm)
{
	printf("llega\n");
	int	i;
(void)envp;
(void)comm;
	i = 0;
	// while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
	// 	i++;
	//comm->paths = ft_split(&envp[i][5], ':');
}

int	is_builtin(t_built *cmd, int ac, char *av[], t_comm comm)
{
	pid_t	child_pid;
	int		stat_loc;

	if (comm.is_builtin)
		builtins(cmd, ac, av, comm);
	else//inicio del executor
	{
		ft_get_paths(cmd->to_env->env_cpy, &comm);
		//printf("no soy un buildin\n");
		//char *argv[] = {"ls", "-l", "-h", "-a", NULL};
		char *argv[] = {"ls", "-lha", NULL};
    	child_pid = fork();
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
			printf("This won't be printed if execvp is successul\n");
		}
		else
		{
			waitpid(child_pid, &stat_loc, WUNTRACED);
		}
	}
	return (0);
}

/*Funcion que segun el comando recibido, redirije a su building corresp.*/
//int	builtings(t_built	*cmd, char	**env, int ac)
int	builtins(t_built *cmd, int ac, char *av[], t_comm comm)
{
	(void)comm;
	if (ca_strcmp(cmd->cmd1, "exit") == 0)
	{
		//printf("exit_teste\n");
		builtin_exit(cmd, ac, av);
		exit (0);
	}
	else if (ca_strcmp(cmd->cmd1, "pwd") == 0)
	{
		//printf("pwd_teste\n");
	 	builtin_pwd();
	}
	else if (ca_strcmp(cmd->cmd1, "cd") == 0)
	{
		builtin_cd(cmd, ac);
		return (0);
	}
	else if (ca_strcmp(cmd->cmd1, "echo") == 0)
	{
		builtin_echo(cmd, ac);
		return (0);
	}
	else if (ca_strcmp(cmd->cmd1, "env") == 0)
	{
		builtin_env();
		return (0);
	}
	// else if (ca_strcmp(cmd->cmd1, "export") == 0)
	// {
	// 	builtin_export(env, ac);
	// 	return (0);
	// }
	// else if (ca_strcmp(cmd->cmd1, "unset") == 0)
	// {
	// 	builtin_unset(env, ac);
	// 	return (0);
	// }
	else
	{
		printf("bash: %s: command not foundeee\n", cmd->cmd1);
	}
	return (0);
}
