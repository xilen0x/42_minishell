
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	//char	**env_cpy;
	t_env	*envlist;
	t_tok	*tok;
	t_cmd	*cmd;

	envlist = NULL;
	tok = NULL;
	cmd = NULL;
	line = NULL;
	if (ac != 1 || av[1])
	{
		ft_msgs(10);
		exit(1);
	}
	//env_cpy = dup_arr2d(envp);//hace falta duplicarlo. No se podria enviar envp a init_list directamente?
	init_envlist(envp, &envlist);
	//free_arr2d(env_cpy);
	// init_msg();
	while (1)
	{
		set_signals();
		minishell(line, tok, envlist, cmd);
	}
	cleaner_envlist(&envlist);
	return (0);
}
