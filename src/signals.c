#include "minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		//printf("\nCtrl-C recibido.\n");
		printf("\n");
		rl_replace_line("", 1);//reemplaza la línea actual de entrada con una cadena vacía.
		rl_on_new_line();// cursor debe moverse a una nueva línea.
		rl_redisplay();//redibuja la línea actual. Se utiliza después de realizar cambios en la línea de entrada para actualizar la pantalla y mostrar los cambios.
	}
	else if (sig == SIGQUIT)
	{
		//printf("\nCtrl-\\ recibido.\n");
		
	}
	return ;
}

void	set_signals(void)
{
	rl_catch_signals = 0;//para eliminar el ^C al hacer ctrl-c
	//ctrl-C 
	signal(SIGINT, signal_handler);

	//ctrl-D 
	signal(SIGQUIT, signal_handler);
}
