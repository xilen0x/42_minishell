#include "minishell.h"

/*-----------Makes an allocated char ** copy-------------*/
char	**env_cpy(char *e[])
{
	char	**env;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (e && e[len])
		len++;
	env = (char **)malloc((len + 1) * sizeof(char *));
	if (env == NULL)
		exit (EXIT_FAILURE);//definirlo en el .h
	while (i < len)
	{
		env[i] = ft_strdup(e[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}
