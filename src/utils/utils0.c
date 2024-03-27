#include "minishell.h"

/*funcion temporal de inicializacion de estructura t_built*/
/*int	init(t_built *cmd, int ac, char *av[])
{
	//!!!queda pendiente implementar la opcion -n!!!
	(void)ac;
	// cmd->export = 0;
	// cmd->unset = 0;
	// cmd->env = 0;
	// cmd->exit = 0;
	// cmd->cd = av[1];
	cmd->cmd1 = av[1];
	cmd->path = av[2];
	// if (av[2])
	// {
	// 	if (ft_strcmp(av[2], "-n") == 0)
	// 	{
	// 		cmd->echo_n = av[2];
	// 		cmd->the_string = av[3];
	// 	}
	// 	else
	// 		cmd->the_string = av[2];
	// }
	return (0);
}*/

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

int bg_color()
{
	printf("\033[44m"); // Imprime la secuencia de escape ANSI para cambiar el fondo a azul
    printf("\033[2J");// Limpia la pantalla para aplicar el nuevo color de fondo en toda la pantalla
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
int	ft_errors(int n)
{
	if (n == 1)
	{
		write (2, "por definir...\n", 53);
		return (1);
	}
	else if (n == 2)
	{
		write (2, "bash: infile: No such file or directory\n", 40);
		exit(1);
	}
	else if (n == 3)
	{
		write (2, "bash: outfile: Permission denied\n", 33);
		exit(1);
	}
	else if (n == 4)
	{
		write (2, "Command not found!\n", 19);
		exit(1);
	}
	else
		write (2, "error", 5);
	return (1);
}