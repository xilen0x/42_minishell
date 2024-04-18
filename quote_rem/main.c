#include "quote_rem.h"
//#include <stdlib.h>
//#include <stdio.h>


int	main(int argc, char **argv)// char **envp)
//int	main(void)
{
	extern char	**environ;
	if (argc != 2 || *argv == NULL)
	{
		printf("introduce arg entrecomillado\n");
		return (0);
	}
	else
	{
	printf("input:%s\n", argv[1]);
	printf("resul:%s\n", quote_removal(*argv, environ));
	}
	return (0);
}