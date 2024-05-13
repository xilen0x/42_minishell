#include "minishell.h"
void	signal_handler(int sig)
{
	if (sig == CTRL_C)
	{
		//printf("\nCtrl-C recibido.\n");
		printf("\n");
		rl_replace_line("", 1);//reemplaza la línea actual de entrada con una cadena vacía.
		rl_on_new_line();// cursor debe moverse a una nueva línea.
		rl_redisplay();//redibuja la línea actual. Se utiliza después de realizar cambios en la línea de entrada para actualizar la pantalla y mostrar los cambios.
		// get_signal = 1;
	}
	else if (sig == CTRL_SLASH)//Existe para justificar el subject
		//printf("\nCtrl-\\ recibido.\n");
	return ;//SE PODRIA ELIMINAR??
}

/*-----Manages Ctrl+C response------*/ 
void	set_signals(void)
{
	rl_catch_signals = 0;//para eliminar el ^C al hacer ctrl-c
	//ctrl-C 
	signal(CTRL_C, signal_handler);

	//ctrl-backslash 
	signal(CTRL_SLASH, signal_handler);//Existe para justificar el subject
}