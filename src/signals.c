#include "minishell.h"

void	signal_parent(int sig)
{
	if (sig == CTRL_C)
	{
		printf("\n");
		rl_replace_line("", 1);//reemplaza la línea actual de entrada con una cadena vacía.
		rl_on_new_line();// cursor debe moverse a una nueva línea.
		rl_redisplay();//redibuja la línea actual. Se utiliza después de realizar cambios en la línea de entrada para actualizar la pantalla y mostrar los cambios.
		get_signal = 1;
	}
}

void	signal_child(int sig)
{
	if (sig == CTRL_C)
		write (2, "\n", 1);
}

int	set_signals(int mode)
{
	rl_catch_signals = 0;
	if (mode == PARENT)
	{
		signal(CTRL_C, signal_parent);
		signal(CTRL_SLASH, signal_parent);//no hace nada. Existe para justificar el subject
	}
	else if (mode == CHILD)
	{
		signal(CTRL_C, signal_child);
	}
	return (1);
}
