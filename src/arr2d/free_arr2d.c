
#include "minishell.h"

/*Frees all elements of an **arr2d included the main pointer as well.*/
void	free_arr2d(char **array_strings)
{
	size_t	i;

	if (array_strings == NULL || array_strings[0] == NULL)
		return ;
	i = 0;
	if (array_strings)
	{
		while (array_strings[i])
		{
			free(array_strings[i]);
			array_strings[i] = NULL;
			i++;
		}
		free(array_strings);
		array_strings = NULL;
	}
}
/*//-------ALTERNATIVA DE HNOS LAJARA----------
// Frees the NULL-terminated array of strings 'arr'.
void	arrstr_free(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(arr);
}*/