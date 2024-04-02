
#include "minishell.h"


int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	//char	**env;
	t_env	env;
	t_tok	*tok;
	t_built	cmds;

	tok = NULL;
	env.env_cpy = dup_arr2d(envp);
	env.export_cpy = dup_arr2d(envp);
	//print_arr2d(env);//ELIMINAR ANTES DE ENTREGA
	//env = dup_arr2d(envp);
	//init_msg();
	if (ac != 1 || av[1])
	{
		ft_errors(5);
		exit(0);
	}
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
		    cmd->cmd1 = strdup(input);//aki voy
		if ((is_builtin(&cmds, ac, av, env)))
		{
			init_momentaneo(av, &env);
			ft_get_paths(env.env_cpy, &env);
			//ft_open_files(av, &data);
			search_cmds(&env);
			executor(&env);
			if (line && *line)
				add_history(line);//si tiene contenido, agregamos 'line' al historial
		//	tokenizer(&tok, line);
		}
		free(line);
	//	init(&cmds, ac, av);//de carlos
	//	builtins(&cmds, env, ac, av);//de carlos
	// 	parser(&cmd, tok);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}

/*
NOTAS:
-preparar el exit_status con los printers de los errores de bash
*/
