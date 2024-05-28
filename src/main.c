
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	t_env	*envlist;

	(void)av;
	g_get_signal = 0;//INIT VAR GLOBAL
	envlist = NULL;
	if (ac != 1)
	{
		ft_msgs(10, NULL);
		exit(EXIT_FAILURE);
	}
	env_init_list(envp, &envlist);
	// bg_color();
	// init_msg();
	while (1)
	{
		set_signals(PARENT);
		minishell(envlist);
	}
	return (0);
}
