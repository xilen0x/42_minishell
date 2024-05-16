
#include "minishell.h"

void	print_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->val)
			printf("%s=%s\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
}

/*builtin que imprime el environment(la copia)*/
int	builtin_env(t_cmd *cmd, t_env *env)
{
	if (size_arr2d(cmd->commands) > 1)
	{//casos especiales
		if ((ft_strcmp(cmd->commands[1], "test") == 0) || \
		(ft_strcmp(cmd->commands[1], "true") == 0) || \
		(ft_strcmp(cmd->commands[1], "false") == 0))
			return (0);
		else if (ft_strcmp(cmd->commands[1], "echo") == 0)
			printf("\n");
		else
			ft_msgs(2, cmd);
		return (0);
	}
	else
		print_env(env);
	return (0);
}
