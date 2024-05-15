
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
//	char	**env_cpy;
	t_env	*envlist;

	envlist = NULL;
	if (ac != 1 || av[1])
	{
		ft_msgs(10);
		exit(EXIT_FAILURE);
	}
//	env_cpy = dup_arr2d(envp);
//	env_init_list(env_cpy, &envlist);
//	free_arr2d(env_cpy);
	env_init_list(envp, &envlist);
//	init_msg();
	while (1)
	{
		set_signals();
		minishell(envlist);
//		printf("get_signal = %i\n", get_signal);
	}
}
