#include "minishell.h"

void	init_msg(void)
{
	printf("\033[44m");
	printf("\n\t%s\
		███    ███ ██ ███    ██ ██  ██████ ██     ██  ████████ ██       ██ %s\n", \
	CYAN, END);
	printf("\t%s\
		██ ████ ██║██║██ ██  ██║██║██ ════╝██╝    ██╝║██══════╝██║      ██║%s \n", \
	CYAN, END);
	printf("\t%s\
		██║╚██ ╝██║██║██║╚██ ██║██║╚█████  █████████ ║████████ ██║      ██║%s \n", \
	CYAN, END);
	printf("\t%s\
		██║ ╚═╝ ██║██║██║  ╚███║██║ ╚═══██ ██ ═══ ██║║██ ═════╝██║      ██║%s\n", \
	CYAN, END);
	printf("\t%s\
		██║     ██║██║██║   ╚██╝██║██████ ╝██║    ██║║████████ ████████ ████████ %s\n", \
	CYAN, END);
	printf("\t%s\
		╚═╝     ╚═╝╚═╝╚═╝    ╚═╝═╝╚══════╝ ╚═╝	  ╚══╝╚═══════╝╚═══════╝╚═══════╝%s\n", \
	CYAN, END);
	printf("%s\n\t\t\tby jocuni-p & castorga%s\t\t\t\n", CYAN, \
		END);
	printf("\t\t\n\n");
	printf("\033[44m");
}

/*Function that changes the color of the terminal*/
int	bg_color(void)
{
	printf("\033[44m"); //fondo a azul
	printf("\033[2J");// Limpia la pantalla
	return (0);
}

/*Funcion que muestra mensaje de error y uso correcto*/
int	ft_msgs(int n)
{
	if (n == 0)
	{
		write (2, "xCommand not found!\n", 20);
		return (1);
	}
	else if (n == 1)
	{
		write (2, "xcannot execute binary file\n", 28);
		return (1);
	}
	else if (n == 2)
	{
		write (2, "xNo such file or directory\n", 27);
		return (1);
	}
	else if (n == 3)
	{
		write (2, "xbash: outfile: Permission denied\n", 34);
		return (1);
	}
	// else if (n == 4)
	// {
	// 	write (2, "xCommand not found!\n", 19);
	// 	return (1);
	// }
	else if (n == 5)
	{
		write (2, "xnot a valid identifier\n", 25);
		return (1);
	}
	else if (n == 6)
	{
		write (2, "xinvalid option\n", 16);
		return (1);
	}
	else if (n == 10)
	{
		write (2, "xRun minishell without arguments!\n", 34);
		exit(0);
	}
	return (1);
}

/*Function that get the exit status number*/
int	get_exit_status(void)
{
	//printf("%d: %s", g_exit_stat, "command not found\n");
	return (0);
}

/*Function that set the exit status number*/
void	set_exit_status(int num)
{
	(void)num;
	//g_exit_stat = num;
}
