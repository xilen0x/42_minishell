
#include "minishell.h"

/*Returns an allocated and NULL terminated copy of **arr_2d*/
char	**dup_arr2d(char **arr2d)
{
	char	**env;
	int		size;
	int		i;

	i = 0;
	size = size_arr2d(arr2d);
	env = (char **)p_malloc((size + 1) * sizeof(char *));
	while (i < size)
	{
		env[i] = ft_strdup(arr2d[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}
