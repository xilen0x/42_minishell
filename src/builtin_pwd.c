#include "minishell.h"

// int	update_pwd(t_env *env)
// {
// 	int		i;
// 	char	*cwd;

// 	i = 0;
// 	cwd = getcwd(NULL, 0); // obtener el directorio de trabajo actual
// 	if (chdir(cwd) != 0)// cambiar el directorio de trabajo actual
// 	{
// 		perror("chdir");
// 		free(cwd);
// 		return -1;
// 	}
// 	while (env->env_cpy[i])
// 	{
// 		if (ft_strnstr(env->env_cpy[i], "PWD=", 4) != NULL)
// 		{
// 			free(env->env_cpy[i]); // Liberar la memoria asignada a la cadena anterior de PWD
// 			env->env_cpy[i] = ft_strjoin("PWD=", cwd); // Actualizar la variable de entorno PWD
// 			free(cwd);
// 			if (env->env_cpy[i] == NULL)
// 			{
// 				perror("ft_strjoin");
// 				return (-1);
// 			}
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	get_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("getcwd");
		return (-1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

int	builtings(t_built	*cmd, t_env	env)
{
	int		i;

	(void)env;
	i = 0;
	if (ft_strcmp(cmd->cmd1, "pwd") == 0)
		get_pwd();
	// else if (ft_strcmp(cmd->cmd1, "cd") == 0)
	// {
	// 	printf("cd\n");
	// 	return (0);
	// }
	// else if (ft_strcmp(cmd->cmd1, "echo") == 0)
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
