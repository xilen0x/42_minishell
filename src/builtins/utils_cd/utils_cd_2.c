#include "minishell.h"

void	update_environment(t_env *env, char *current_wd)
{
	update_pwd(env);
	update_oldpwd(env, current_wd);
}

int	free_current_wd(char *current_wd)
{
	if (current_wd != NULL && *current_wd != '\0')
	{
		free(current_wd);
		return (1);
	}
	return (0);
}
