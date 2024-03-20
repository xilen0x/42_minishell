#include "minishell.h"
#include <signal.h>

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		//printf("\nCtrl-C recibido.\n");
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		printf("\nCtrl-D recibido.\n");
		exit(127);
	}
	return ;
}

void	set_signals(void)
{
	//ctrl-C 
	signal(SIGINT, signal_handler);

	//ctrl-D 
	signal(SIGQUIT, signal_handler);

	//ctrl-slash

}
