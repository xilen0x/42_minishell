#include "quote_rem.h"
//#include <stdlib.h>
//#include <stdio.h>


int	main(int argc, char **argv)
{
	t_env 		*envlist;
	extern char	**environ;

	envlist = NULL;
	if (argc != 2 || *argv == NULL)
	{
		printf("introduce arg entrecomillado\n");
		return (0);
	}
	printf("input:%s\n", argv[1]);
	printf("pos 1 del environ:%s\n", environ[1]);

	init_list(environ, &envlist);
	printf("--------NOMBRES DE VAR DE ENTORNO--------\n");
	ft_print_keys(envlist);
	printf("--------CONTENTS DE ENTORNO--------\n");
	ft_print_values(envlist);

	printf("resul:%s\n", quote_removal(*argv, envlist));
	return (0);
}