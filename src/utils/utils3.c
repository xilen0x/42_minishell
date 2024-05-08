#include "minishell.h"

void	free_memory(char **array, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

//executor init data
int	init_exe(t_exe *exe, t_cmd *cmd)
{
	exe->num_cmds = cmd_size(cmd);
	exe->fd[0] = -1;
	exe->fd[1] = -1;
	exe->pid = malloc(sizeof(pid_t) * exe->num_cmds);
	if (!exe->pid)
		return (1);
	return (0);
}

void	error_exe(int num)
{
	if (num == 1)
	{
		perror("Pipe failed");
		exit(1);
	}
	else if (num == 2)
	{
		perror("Fork failed");
		exit(1);
	}
}

void	allocate_memory(t_env *current, int len, t_exe *exe)
{
	int		i;

	i = 0;
	while (current && i < len)
	{
		exe->new_array[i] = ft_strjoin(current->key, current->val);
		if (exe->new_array[i] == NULL)
		{
			free_memory(exe->new_array, i);
			return ;
		}
		current = current->next;
		i++;
	}
}

/*convert the env(list) to an array(char **)*/
int	list_to_array(t_env *env, t_exe *exe)
{
	int		len;
	t_env	*current;

	len = 0;
	current = env;
	while (current)
	{
		len++;
		current = current->next;
	}
	exe->new_array = (char **)malloc(sizeof(char *) * (len + 1));
	if (exe->new_array == NULL)
		return (-1);
	current = env;
	allocate_memory(current, len, exe);
	exe->new_array[len] = NULL;
	return (0);
}
