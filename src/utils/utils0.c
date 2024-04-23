#include "minishell.h"

/*function that prints a welcome message*/
void	init_msg(void)
{
	printf("           _       _     _          _ _ \n");
	printf("          (_)     (_)   | |        | | |\n");
	printf(" _ __ ___  _ _ __  _ ___| |__   ___| | |\n");
	printf("| '_ ` _ \\| | '_ \\| / __| '_ \\ / _ \\ | |\n");
	printf("| | | | | | | | | | \\__ \\ | | |  __/ | |\n");
	printf("|_| |_| |_|_|_| |_|_|___/_| |_|\\___|_|_|\n");

	printf("by jocuni-p & castorga\n\n\n\n");
}

/*Function that changes the color of the terminal*/
int	bg_color(void)
{
	printf("\033[44m"); //fondo a azul
	printf("\033[2J");// Limpia la pantalla
	return (0);
}

// void	print_env(char **env)
// {
// 	int	i = 0;

// 	while (env[i])
// 	{
// 		printf("%s\n", env[i]);
// 		i++;
// 	}
// }

/*Funcion que muestra mensaje de error y uso correcto*/
int	ft_msgs(int n)
{
	if (n == 1)
	{
		write (2, "cannot execute binary file\n", 27);
		return (1);
	}
	else if (n == 2)
	{
		write (2, "No such file or directory\n", 26);
		return (1);
	}
	else if (n == 3)
	{
		write (2, "bash: outfile: Permission denied\n", 33);
		return (1);
	}
	else if (n == 4)
	{
		write (2, "Command n*ot found!\n", 19);
		return (1);
	}
	else if (n == 5)
	{
		write (2, "xnot a valid identifier\n", 24);
		return (1);
	}
	else if (n == 6)
	{
		write (2, "make: *** No targets specified and no makefile found.  Stop.\n", 61);
		return (1);
	}
	else if (n == 10)
	{
		write (2, "Run minishell without arguments!\n", 33);
		exit(0);
	}

	return (1);
}

/*Function that return the exit status number*/
int	exit_status(void)
{
	t_shell	num;

	return (num.exit_status);
}

/*nota: hacer funcion exit_status tipo getter y setter*/