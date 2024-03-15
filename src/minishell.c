
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;//contendra la linia que se ingrese por stdin
	//char	**env;//contendra una copia del env del sistema
	t_env	env;
	//t_lst	**tokens;
	t_built	cmds;


	/*if (ac != 1 || av[1])//si hay algun argumento
	{
		printf("minishell do not accept arguments\n");
		return (EXIT_FAILURE);
	}*/
	env.env_cpy = dup_arr2d(envp);//duplica el env del sistema
	//env = dup_arr2d(envp);
	env.export_cpy = dup_arr2d(envp);
	while (1)//loop infinito hasta que se presione Ctrl+D(printa exit y sale), 'exit'(printa exit\n y sale)o se cierre el programa
	{
//		poner las señales en escucha y hacer funcion para gestionarlas(handler ??)	
		line = readline(">>>>minishell$ ");//ojo retorna un *str mallocado
		// if (!line)
		// 	return (exit_status)
		add_history(line);//agregamos 'line' al historial, lo gestiona biblioteca readline
//		gestionar Ctrl+C (para que interrumpa el proceso actual, invocando a SIGINT y presente el prompt de nuevo)

		//tokens = tokenizer(line);//DESARROLLAR ESTO ASAP (retorna un t_lst **)

		init(&cmds, ac, av);//de carlos
		builtins(&cmds, env, ac, av);//de carlos
		free(line);//libero la linia que retorno readline seguramente mallocada
//		parser(la struct/list con los tokens);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}

/*
Note: 
*/