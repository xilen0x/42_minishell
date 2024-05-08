#include "minishell.h"

/*Displays all elements contained in a bi-dimensional array*/
void	print_arr2d(char **arr2d)
{
	size_t	size;

	size = 0;
	while (arr2d && arr2d[size])
	{
		printf("%s\n", arr2d[size]);
		size++;
	}
	return ;
}

/*dejar uno de estos dos(print_arr2d o este)*/
void	print_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
	{
		printf("El array es NULL\n");
		return ;
	}
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
}
