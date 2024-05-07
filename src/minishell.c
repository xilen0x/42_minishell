
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
	unsigned int exit_status;

	envlist = NULL;
	tok = NULL;
	cmd = NULL;
	exit_status = 555;//inicializo provisionalmente, para que tenga algun valor
	if (ac != 1 || av[1])
	{
		ft_errors(5);
		exit(0);
		return (0);
	}
//	env.env_cpy = dup_arr2d(envp);
	env_cpy = dup_arr2d(envp);
//	env.export_cpy = dup_arr2d(envp);
	//init_msg();
	//bg_color();
	init_envlist(env_cpy, &envlist);
	free_arr2d(env_cpy);//lo libero, porque ya lo tengo guardado en envlist

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
		if (strcmp(line, "exit") == 0)
		{
			cleaner_envlist(&envlist);
			free(line); 
			return(0);
		}
		if (line && *line)
			add_history(line);
		if (!*line)
		{
			free(line);
			continue;
		}
		tokenizer(&tok, line);//crea una lista de tokens tok
		free(line);
	  	parser(&cmd, tok);//crea una nueva lista cmd a partir de la lista tok
		tok_free(&tok);
		should_expand(&cmd, envlist, &exit_status);

		//	builtins(&cmds, env, ac, av);//de carlos
//		ft_get_paths(env.env_cpy, &env);
		//ft_open_files(av, &data);
//	search_cmds(&env);
//		executor(&env);
//		print_cmd_para_executor(cmd);
		cmd_free(&cmd);//libera toda la lista cmd
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	cleaner_envlist(&envlist);//libera la lista de env
	return (0);
}
//SI NO HAY CIERRE DE COMILLAS lo gestionaré como => syntax error near token 'print_del_token'???