
#include "minishell.h"


int	main(int ac, char *av[], char *envp[])
{
	char	*line;//la linia que ingresa el prompt
	char	**env;//la copia del env del zsh
//	t_env	env;
	t_lst	*tokens;//la lista de tokens
//	t_comm	*comm;//la lista de pipelines/comandos
//	t_built	cmds;

	tokens = NULL;
//	comm = NULL;
	if (ac != 1 || av[1])
	{
		printf("'minishell' do not accept arguments\n");
		return (EXIT_FAILURE);
	}
	env = dup_arr2d(envp);
	print_arr2d(env);//ELIMINAR ANTES DE ENTREGA
	while (1)
	{
//		poner las señales en escucha y hacer funcion para gestionarlas(handler ??)	
//		gestionar Ctrl+C (para que interrumpa el proceso actual, invocando a SIGINT y presente el prompt de nuevo)
		line = readline(">>>>minishell$ ");//ojo retorna un *str mallocado
		if (!line)//ESTO ES UTIL Y NECESARIO???
		 	return (write(1, "!line\n", 6), 0);//OJO gestionar esto
		if (line && *line)//si no hay nada en la linea no se registra en history y debe mostrar una nueva linea
			add_history(line);//agregamos 'line' al historial, lo readline
		tokenizer(tokens, line);
		free(line);//libero la linia que retorna readline, seguramente mallocada
	//	init(&cmds, ac, av);//de carlos
	//	builtins(&cmds, env, ac, av);//de carlos
	//	jc_lstclear(&tokens);
//		parser(comm, tokens);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}
/*
NOTAS:
-Las comillas (quote removal) y los expanders gestionarlos entre el parser y el executor
-preparar el exit_status con los printers de los errores de bash
*/