#include "minishell.h"

/*Displays all elements contained in a bi-dimensional array*/
/*
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
*/
/*----Cualquiera de las 2 funciones son validas----*/
void	print_arr2d(char **arr2d)
{
	int	i;

	i = 0;
	if (arr2d == NULL)
	{
		printf("El array es NULL\n");
		return ;
	}
	while (arr2d[i] != NULL)
	{
		printf("%s\n", arr2d[i]);
		i++;
	}
}
