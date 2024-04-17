
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	// t_env	*env;
	t_tok	*tok;
	t_cmd	*cmd;
	t_shell	shell;

	tok = NULL;
	// env = NULL;
	cmd = NULL;
	if (ac != 1 || av[1])
		ft_msgs(10);
	//main_struct.exit_status = 0;
	//env.env_cpy = dup_arr2d(envp);//copia anterior environment
	// shell.link_env = init_list(envp, &shell);
	init_list(envp, &shell);
	//exe = get_paths(env, exe);
	//init_msg();
	bg_color();
	while (1)
	{
		set_signals();
		line = readline(">>>>minishell$ ");
		if (!line)
		{
			printf("exit\n");//en el caso del ctrl-D
			exit(0);
		}
		if (line && *line)
			add_history(line);
		else
			continue ;
		tokenizer(&tok, line);
		free(line);
	  	parser(&cmd, tok);
		//redireciones...
		if (builtins(cmd, av, &shell))
		{
			get_paths(&shell);
			//ft_open_files(av, &data);
			search_command_path(&shell);
			//executor(env, *cmd);
		}
		if (cmd || tok)//verificar si es necesario este if
		{
			cmd_free(&cmd);
			tok_free(&tok);
		}
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}

/*
NOTAS:
-preparar el exit_status con los printers de los errores de bash
*/
