#include "minishell.h"

// int	update_pwd(t_shell *shell, char	*cwd)
// {
// 	int		i;

// 	i = 0;
// 	while (shell != NULL)
// 	{
// 		if (ca_strcmp(shell->link_env->key, "PWD") == 0)
// 		{
// 			shell->link_env->val = cwd;
// 			return (0);
// 		}
// 		shell->link_env = shell->link_env->next;
// 	}
// 	return (1);
// }


/*Funcion que retorna el path actual(pwd). Utiliza para ello la funcion getcwd*/
int	builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("getcwd");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

/*
// 	t_env	*env;
	int		i;
	
	update_pwd(shell, cwd);
	//shell->link_env->val = cwd;
	env = shell->link_env;
	i = 0;
	while (env != NULL)
	{
		if (ca_strcmp(env->key, "PWD") == 0)
		{
			//printf("PATH=%s\n", env->val);
			shell->link_env->val = env->val;
			break ;
		}
		i++;
		env = env->next;
	}
*/