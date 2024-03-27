
#include "minishell.h"


int	main(int ac, char *av[], char *envp[])
{
	(void)ac;
	char	*line;//la linia que se ingrese por stdin
	//char	**env;//la copia del env del zsh
	t_env	env;
	t_lst	*tokens;//la lista de los tokens
	//t_built	cmds;
	t_env	data;

	tokens = NULL;
	// if (ac != 1 || av[1])
	// {
	// 	printf("No such file or directory\n");
	// 	return (EXIT_FAILURE);
	// }
	env.env_cpy = dup_arr2d(envp);
	env.export_cpy = dup_arr2d(envp);
	//print_arr2d(env);//ELIMINAR ANTES DE ENTREGA
	//bg_color();
	//init_msg();
	while (1)//loop infinito hasta que se presione Ctrl+D(printa exit y sale), 'exit'(printa exit\n y sale)o se cierre el programa
	{
		set_signals();
		line = readline(">>>>minishell$ ");//ojo retorna un *str mallocado
		if (!line)
		{
			//printf("control-D recibido!\n");
			printf("\033[0m");// Restaurar color de fondo a su estado original al finalizar
			exit(0);
		}
//		parser(la struct/list con los tokens);
		//init(&cmds, ac, av);//de carlos - eliminiar luego cmds
		init_momentaneo(av, &data);
		ft_get_paths(env.env_cpy, &data);
		//ft_open_files(av, &data);
		search_cmds(&data);
		executor(&data);
		if (line && *line)//si no hay nada en la linea no se registra en history y debe mostrar una nueva linea
			add_history(line);//agregamos 'line' al historial, lo readline
		//tokenizer(tokens, line);
		//builtins(&cmds, ac, av, env);
		//is_builtin(&cmds, ac, av);
		free(line);//libero la linia que retorna readline, seguramente mallocada
	//	lst_clear(&tokens);
	  //parser(cmd, tokens);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}
/*
NOTAS:
-Las comillas (quote removal) y los expanders gestionarlos entre el parser y el executor
-preparar el exit_status con los printers de los errores de bash
*/
