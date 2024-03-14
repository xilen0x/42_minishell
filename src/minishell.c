
#include "../include/minishell.h"

//#include "libft/libft.h"
/*funcion temporal de inicializacion de estructura t_built*/
/*
void	init(t_built *cmd, char *av[])
{
	cmd->echo = 0;
	cmd->cd = 0;
	cmd->pwd = 0;
//	cmd->export = 0;
	cmd->unset = 0;
	cmd->env = NULL;
	cmd->exit = 0;
	cmd->cmd1 = av[1];
	cmd->path = av[2];
}*/

int	main(int ac, char *av[], char *envp[])
{
	//t_env	env;
	char	*line;//contendra la linia que se ingrese por stdin
	char	**env;//contendra una copia del env del sistema
	t_lst	**tokens;
//	t_built	cmds;

	if (ac != 1 || av[1])//si hay algun argumento
	{
		printf("minishell do not accept arguments\n");
		return (EXIT_FAILURE);
	}
	env = dup_arr2d(envp);//duplica el env del sistema
	//env.env_cpy = env_cpy(envp);
	while (1)//loop infinito hasta que se presione Ctrl+D(printa exit y sale), 'exit'(printa exit\n y sale)o se cierre el programa
	{
//		poner las señales en escucha y hacer funcion para gestionarlas(handler ??)	
		line = readline(">>>>minishell$ ");//ojo retorna un *str mallocado
		if (!line)
			return (write(1, "!line\n", 6), 0);//gestionar que hacemos exactamente si pasa esto
		if (line != NULL)//hablar con Carlos, no entiendo que hace esto?????????
		{
			write(1, "exit\n", 5);
			exit(1);//carlos, es el codigo de error?
		}
			add_history(line);//agregamos 'line' al historial, lo gestiona biblioteca readline
//		gestionar Ctrl+C (para que interrumpa el proceso actual, invocando a SIGINT y presente el prompt de nuevo)

		tokens = tokenizer(line);//DESARROLLAR ESTO ASAP (retorna un t_lst **)

//		init(&cmds, av);//de carlos
//		builtings(&cmds, env, ac);//de carlos
		free(line);//libero la linia que retorno readline seguramente mallocada
//		parser(la struct/list con los tokens);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}
