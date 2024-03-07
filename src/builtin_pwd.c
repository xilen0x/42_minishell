#include "minishell.h"

char	*get_pwd(char *cmd, t_env	env)
{
	int	i;

	(void)cmd;
	i = 0;
	while (ft_strnstr(env.env_cpy[i], "PWD=", 4) == NULL)
		i++;
	printf("%s\n", env.env_cpy[i] + 4);
	return (0);
}
// int	set_pwd(char *cmd, t_env	env)
// {
// 	int	i;

// 	(void)cmd;
// 	i = 0;
// 	while (ft_strnstr(env.env_cpy[i], "PWD=", 4) == NULL)
// 		i++;
// 	printf("%s\n", env.env_cpy[i] + 4);
// 	return (0);
// }

int	builtings(t_built	*cmd, t_env	env)
{
	int	i;

	i = 0;
	if ((ft_strcmp(cmd->cmd1, "pwd")) == 0)
	{
		get_pwd(cmd->cmd1, env);
		return (0);
	}
	// else if ((ft_strcmp(cmd->cmd1, "cd")) == 0)
	// {
	// 	printf("cd\n");
	// 	return (0);
	// }
	// else if ((ft_strcmp(cmd->cmd1, "echo")) == 0)
	// {
	// 	printf("echo\n");
	// 	return (0);
	// }
	else
	{
		printf("no soy un comando\n");
	}
	return (0);
}
