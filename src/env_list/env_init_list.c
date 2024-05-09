#include "minishell.h"

/* Copies the entire env into a new malloced 't_env' list*/
void	init_envlist(char **envp, t_env **envlist)
{
	int		i;
	char	**tokens;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		tokens = ft_split(envp[i], '=');//Divide cada linea del env en 'key' y 'val'
		if (tokens != NULL && tokens[0] != NULL && tokens[1] != NULL)
		{
			key = tokens[0];
			value = tokens[1];
			lstadd_back(envlist, lstnew(key, value));
		}
		free_arr2d(tokens);//libera el malloc que entrega el split a tokens
		i++;
	}
	return ;
}