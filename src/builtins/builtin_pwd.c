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

int	variable_exists_pwd(t_env *env, char *path)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (env != NULL)
	{
		if (ca_strcmp(path, env->key) == 0)
		{
			env->val = path;//aki voy!!!!
			flag = 1;
		}
		i++;
		env = env->next;
	}
	return (flag);
}

/*Funcion que retorna el path actual(pwd). Utiliza para ello la funcion getcwd*/
int	builtin_pwd(t_env *env)
{
	char	*current_wd;

	current_wd = getcwd(NULL, 0);
	if (!current_wd)
	{
		perror("getcwd");
		free(current_wd);
	}
	variable_exists_pwd(env, current_wd);
	printf("%s\n", current_wd);
	free(current_wd);
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