
#include "minishell.h"

void	print_env(t_env *env)
{
	// t_env	*tmp;

	// tmp = env;
	while (env)
	{
		if (env->val)
			printf("%s=%s\n", env->key, env->val);
		env = env->next;
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
			return (1);
		else if (ft_strcmp(cmd->commands[1], "echo") == 0)
		{
			printf("\n");
			return (0);
		}
		else
			ft_msgs(2, cmd);
		return (1);
	}
	else
		print_env(env);
	return (0);
}
