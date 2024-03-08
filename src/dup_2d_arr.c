
#include "../include/minishell.h"

/*Returns an allocated and NULL terminated copy of **arr_2d*/
char	**dup_2d_arr(char **arr_2d)
{
	char	**env;
	int		size;
	int		i;   

	i = 0;
	size = size_2d_arr(arr_2d);
	env = (char **)malloc((size + 1) * sizeof(char *));
	if (env == NULL)
		exit (EXIT_FAILURE);//definir en el .h  ???
	while (i < size)
	{
		env[i] = ft_strdup(*arr_2d[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}