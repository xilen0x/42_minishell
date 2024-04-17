
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	t_env	*env;
	t_tok	*tok;
	t_cmd	*cmd;
	t_exe	*exe;

	tok = NULL;
	env = NULL;
	cmd = NULL;
	exe = NULL;
	if (ac != 1 || av[1])
	{
		ft_msgs(10);
		exit(0);
	}
	//main_struct.exit_status = 0;
	//env.env_cpy = dup_arr2d(envp);//copia anterior environment
	env = init_list(envp, env);
	//init_msg();
	bg_color();
	while (1)
	{
		set_signals();
		line = readline(">>>>minishell$ ");
		if (!line)
		{
			printf("exit\n");//en el cado del ctrl-D
			exit(0);
		}
		if (line && *line)
			add_history(line);//si tiene contenido, agregamos 'line' al historial
		else
			continue;
		tokenizer(&tok, line);
		free(line);
	  	parser(&cmd, tok);
		//redireciones...
		get_paths(env);
		if (builtins(cmd, av, env, exe))
		{
			//get_paths(env);
			//ft_open_files(av, &data);
			//search_cmds(&env);
			search_command_path(*cmd->command_and_arg, exe);
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
