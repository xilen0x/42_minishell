
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	t_env	env;
	t_tok	*tok;
	//t_shell	main_struct;
	t_cmd	*cmd;

	tok = NULL;
	cmd = NULL;
	if (ac != 1 || av[1])
	{
		ft_msgs(5);
		exit(0);
	}
	//main_struct.exit_status = 0;
	env.env_cpy = dup_arr2d(envp);
	//env.export_cpy = dup_arr2d(envp);
	//print_arr2d(env);//ELIMINAR ANTES DE ENTREGA
	//init_msg();
	bg_color();
	while (1)
	{
		set_signals();
		line = readline(">>>>minishell$ ");
		if (!line)
		{
			printf("exit\n");//en el cado del ctrl-D
			//printf("\033[0m");// Restaurar color de fondo a su estado original al finalizar
			exit(0);
		}
		if (line && *line)
			add_history(line);//si tiene contenido, agregamos 'line' al historial
		else
			continue;
		tokenizer(&tok, line);
		free(line);
	  	parser(&cmd, tok);
		//printf("%s\n", cmd->command_and_arg[0]);
		//printf("%s\n", cmd->command_and_arg[1]);
		//redireciones...
		if (builtins(cmd, ac, av, env))
		{
			ft_get_paths(env.env_cpy, &env);
			//ft_open_files(av, &data);
			//search_cmds(&env);
			search_command_path(*cmd->command_and_arg, &env);
			executor(&env, *cmd);
		}
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
