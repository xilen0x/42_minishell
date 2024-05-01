
#include "minishell.h"

//int	main(int ac, char *av[])// char *envp[])
int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	char	**env_cpy;
	t_env	*envlist;
	t_tok	*tok;
	//t_built	cmds;
	t_cmd	*cmd;

	envlist = NULL;
	tok = NULL;
	cmd = NULL;
	if (ac != 1 || av[1])
	{
		ft_errors(5);
		exit(0);
	}
//	env.env_cpy = dup_arr2d(envp);
	env_cpy = dup_arr2d(envp);
//	env.export_cpy = dup_arr2d(envp);
	//init_msg();
	//bg_color();
	init_envlist(env_cpy, &envlist);
	while (1)
	{
		set_signals();
		line = readline(">>>>minishell$ ");
		if (!line)
		{
			printf("exit\n");//para el caso del ctrl-D
			//printf("\033[0m");// Restaurar color de fondo a su estado original al finalizar
			exit(0);
		}
		if (line && *line)
			add_history(line);
		if (!*line)
		{
			free(line);
			continue;
		}
		tokenizer(&tok, line);
		free(line);
	  	parser(&cmd, tok);
//		tok_free(&tok);
		should_expand(&cmd, envlist);

		//	builtins(&cmds, env, ac, av);//de carlos
//		ft_get_paths(env.env_cpy, &env);
		//ft_open_files(av, &data);
//	search_cmds(&env);
//		executor(&env);
		cmd_free(&cmd);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}
//SI NO HAY CIERRE DE COMILLAS lo gestionaré como => syntax error near token 'print_del_token'???