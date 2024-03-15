
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;//la linia que se ingrese por stdin
	char	**env;//la copia del env del zsh
	t_lst	*tokens;//la lista de los tokens

	tokens = NULL;
	if (ac != 1 || av[1])//proteccion por si lo ejecutan con argumentos
	{
		printf("'minishell' do not accept arguments\n");
		return (EXIT_FAILURE);
	}
	env = dup_arr2d(envp);
//	print_arr2d(env);//ELIMINAR ANTES DE ENTREGA
	while (1)//loop infinito hasta que se presione Ctrl+D(printa exit y sale), 'exit'(printa exit\n y sale)o se cierre el programa
	{
//		poner las señales en escucha y hacer funcion para gestionarlas(handler ??)	
		line = readline(">>>>minishell$ ");//ojo retorna un *str mallocado
		if (!line)
			return (write(1, "!line\n", 6), 0);//OJO gestionar esto
		add_history(line);//agregamos 'line' al historial, lo gestiona biblioteca readline
//		gestionar Ctrl+C (para que interrumpa el proceso actual, invocando a SIGINT y presente el prompt de nuevo)
		tokenizer(tokens, line);

		free(line);//libero la linia que retornó 'readline'
//		parser(la list con los tokens);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}
TO DO: arreglar cuando le llega doble operador que lo cuenta dos veces