# include "minishell.h"

/*function that search by the 'PATH' word and split the content*/
char	**get_paths(t_env *env)
{
//	int		i;
	char	**full_path;

//	i = 0;
	full_path = NULL;
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
		{
			full_path = ft_split(env->val, ':');
			break ;
		}
//		i++;
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
		{
			get_signal = 127;
			return (-1);
		}
		if (access(full_path, F_OK) == 0)
		{
			exe->cmd_fullpath = full_path;
			return (0);
		}
		else
			get_signal = 1;
		free(full_path);
		i++;
	}
	return (1);
}
