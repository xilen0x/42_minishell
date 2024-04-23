
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])//PROVAR DE OBTENER EL ENV CON LA VARIABLE **ENVIRON
{
	char	*line;
	t_tok	*tok;
	t_cmd	*cmd;
	t_shell	shell;

	tok = NULL;
	cmd = NULL;
	if (ac != 1 || av[1])
		ft_msgs(10);
	init_main_struct(&shell);
	init_list(envp, &shell);
	bg_color();
	//init_msg();
	while (1)
	{
		set_signals();
		line = readline(">>>>minishell$ ");
		if (!line)
		{
			printf("exit\n");//en el caso del ctrl-D
			//printf("\033[0m");// Restaurar color de fondo a su estado original al finalizar
			exit(0);
		}
		if (line && *line)
			add_history(line);
		if (!*line)//else
		{
			free(line);
			continue ;
		}
		tokenizer(&tok, line);
		free(line);
	  	parser(&cmd, tok);
		if (builtins(cmd, av, &shell))
		{
			get_paths(&shell);
			//ft_open_files(av, &data);
			search_command_path(&shell);
			//executor(env, *cmd);
		}
//		should_expand_var(&cmd);
//		expander(&cmd, exit);
		tok_free(&tok);
		cmd_free(&cmd);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}

/*
NOTAS:
-preparar el exit_status con los printers de los errores de bash
*/
