
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	char	**env_cpy;
	t_env	*envlist;
	t_tok	*tok;
	t_cmd	*cmd;
	unsigned int exit_status;

	envlist = NULL;
	tok = NULL;
	cmd = NULL;
	exit_status = 555;//inicializo provisionalmente, para que tenga algun valor
	if (ac != 1 || av[1])
	{
		ft_msgs(10);
		exit(1);
//		return (0);
	}
	env_cpy = dup_arr2d(envp);
	init_envlist(env_cpy, &envlist);
	free_arr2d(env_cpy);//lo libero, porque ya lo tengo guardado en envlist
	//init_main_struct(&shell);
	bg_color();
	//init_msg();
	while (1)
	{
		set_signals();
		line = readline(">>>>minishell$ ");
		if (!line)
		{
			printf("exit\n");//en el caso del ctrl-D
			printf("\033[40m");//black
			exit(0);
		}
//----OJO si funciona el builtin borrar este
/*		if (strcmp(line, "exit") == 0)
		{
			cleaner_envlist(&envlist);
			free(line); 
//			return(0);
			exit (EXIT_FAILURE);
		}*/
		if (line && *line)
			add_history(line);
//		if (!*line)
//		{
//			free(line);
//			continue;
//		}
		tokenizer(&tok, line);//crea una lista de tokens tok
		free(line);

	  	parser(&cmd, tok);//crea una nueva lista cmd a partir de la lista tok
		tok_free(&tok);
		should_expand(cmd, envlist, &exit_status);
		executor(&envlist, cmd);
		cmd_free(&cmd);//libera toda la lista cmd
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	cleaner_envlist(&envlist);//libera la lista de env
	return (0);
}
//SI NO HAY CIERRE DE COMILLAS lo gestionaré como => syntax error near token 'print_del_token'???