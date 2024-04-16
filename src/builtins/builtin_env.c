
#include "minishell.h"

/*builtin que imprime el environment(la copia)*/
int	builtin_env(t_cmd *cmd, t_env env)
{
	int		i;

	i = 0;
	if (size_arr2d(cmd->command_and_arg) > 1)
	{//casos especiales
		if ((ca_strcmp(cmd->command_and_arg[1], "test") == 0) || \
		(ca_strcmp(cmd->command_and_arg[1], "true") == 0) || \
		(ca_strcmp(cmd->command_and_arg[1], "false") == 0))
			return (0);
		else if (ca_strcmp(cmd->command_and_arg[1], "echo") == 0)
			printf("\n");
		else
			ft_msgs(2);
		return (0);
	}
	else
	{
		// while (env.env_cpy[i])
		// {
		// 	printf ("%s\n", env.env_cpy[i]);
		// 	i++;
		// }
		ft_printstack(&env);
	}
	return (0);
}
