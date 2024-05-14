#include "minishell.h"

//OJO: REVISAR SI HACE FALTA, porque ya tenemos free_arr2d para liberar un char**
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
	char	*tmp;
	i = 0;
	while (current && i < len)
	{
		tmp = ft_strjoin(current->key, "=");
		exe->new_array[i] = ft_strjoin(tmp, current->val);
		free(tmp);
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
