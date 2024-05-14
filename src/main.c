
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;//se podria declarar en minishell
//	char	**env_cpy;
	t_env	*envlist;
//	t_tok	*tok;//se podria declarar en minishell
//	t_cmd	*cmd;//se podria declarar en minishell

	envlist = NULL;
//	tok = NULL;
//	cmd = NULL;
	line = NULL;
	if (ac != 1 || av[1])
	{
		ft_msgs(10);
		exit(EXIT_FAILURE);
	}
//	env_cpy = dup_arr2d(envp);//hace falta duplicarlo? No se podria enviar envp a init_list directamente?
//	env_init_list(env_cpy, &envlist);
//	free_arr2d(env_cpy);
	env_init_list(envp, &envlist);
	init_msg();
	while (1)
	{
		set_signals();
		minishell(line, envlist);
	}
//	cleaner_envlist(&envlist);//AQUI NO LLEGA NUNCA, DEBERIA ESTAR EN EL 'exit' o en el 'Ctrl+D' 
}
