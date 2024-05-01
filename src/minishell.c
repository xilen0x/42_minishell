
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	char	**env_cpy;
	t_env	*envlist;
	t_tok	*tok;
	t_cmd	*cmd;

	envlist = NULL;
	tok = NULL;
	cmd = NULL;
	if (ac != 1 || av[1])
		ft_msgs(10);
	env_cpy = dup_arr2d(envp);
	//init_main_struct(&shell);
	//init_list_env(envp, &shell);
	init_envlist(env_cpy, &envlist);
	bg_color();
	//init_msg();
	while (1)
	{
		/*
		NOTA PARA MANANA: WIP en test folder. Eliminando el promer nodo al parecer exitosamente. Faltaria
		integrar y probar en funcion unset para controlar el error al eliminar el primer nodo.
		*/
		set_signals();
		line = readline(">>>>minishell$ ");
		if (!line)
		{
			printf("exit\n");//en el caso del ctrl-D
			printf("\033[40m");//black
			exit(0);
		}
		if (line && *line)
			add_history(line);
		if (!*line)
		{
			free(line);
			continue ;
		}
		tokenizer(&tok, line);
		free(line);
		parser(&cmd, tok);
//		ft_open_files(av, &data);
//		should_expand_var(&cmd);
//		expander(&cmd, exit);
		executor(envlist, cmd);
		tok_free(&tok);
		cmd_free(&cmd);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}
//SI NO HAY CIERRE DE COMILLAS lo gestionaré como => syntax error near token 'print_del_token'???