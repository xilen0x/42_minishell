
#include "../include/minishell.h"

//#include "libft/libft.h"


int	main(int ac, char *av[], char *envp[])
{
	char	*line;//contendra la linia que se ingrese por stdin
	char	**env;//contendra una copia del env del zsh
	t_lst	tokens;

if (ac != 1 || av[1])//si hay algun argumento
	{
		printf("'minishell' do not accept arguments\n");
		return (EXIT_FAILURE);
	}
	env = dup_arr2d(envp);//duplica el env del zsh
	print_arr2d(env);//ELIMINAR ANTES DE ENTREGA
	while (1)//loop infinito hasta que se presione Ctrl+D(printa exit y sale), 'exit'(printa exit\n y sale)o se cierre el programa
	{
//		poner las señales en escucha y hacer funcion para gestionarlas(handler ??)	
		line = readline(">>>>minishell$ ");//ojo retorna un *str mallocado
		if (!line)
			return (write(1, "!line\n", 6), 0);//gestionar que hacemos exactamente si pasa esto
		add_history(line);//agregamos 'line' al historial, lo gestiona biblioteca readline
//		gestionar Ctrl+C (para que interrumpa el proceso actual, invocando a SIGINT y presente el prompt de nuevo)
		printf("antes de entrar a tokenizer\n");
		tokenizer(&tokens, line);

		free(line);//libero la linia que retorno readline seguramente mallocada
//		parser(la list con los tokens);
	}
	write(1, "ojo, aqui NO deberia llegar nunca\n", 34);
	return (0);
}