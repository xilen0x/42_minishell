
#include "../include/minishell.h"


char	**dup_array_2d(char **array_2d)
{
	char	**env;
	int		len;
	int		i;   

	i = 0;
	len = 0;
	while (array_2d && array_2d[len])//SUSTITUIR POR FUNCION size_t array_2d_size
		len++;
	env = (char **)malloc((len + 1) * sizeof(char *));
	if (env == NULL)
		exit (EXIT_FAILURE);//definirlo en el .h  ???
	while (i < len)
	{
		env[i] = ft_strdup(*array_2d[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}