
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	t_env	*envlist;

	g_get_signal = 0;//INIT GLOBAL VAR
	envlist = NULL;
	if (ac != 1 || av[1])
	{
		ft_msgs(10, NULL);
		exit(EXIT_FAILURE);
	}
	env_init_list(envp, &envlist);
	// init_msg();
	while (1)
	{
		set_signals(PARENT);
		minishell(envlist);
	}
	return (0);
}
