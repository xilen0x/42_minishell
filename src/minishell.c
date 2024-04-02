
#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	char	*line;
	char	**env;
	t_tok	*tok;
	t_cmd	*cmd;
//	t_built	cmds;

	tok = NULL;
	cmd = NULL;
	if (ac != 1 || av[1])
	{
		printf("'minishell' do not accept arguments\n");
		return (EXIT_FAILURE);
	}
	env = dup_arr2d(envp);
//	print_arr2d(env);//ELIMINAR ANTES DE ENTREGA
	while (1)
	{
//		poner las señales en escucha y hacer funcion para gestionarlas(handler ??)	
		line = readline(">>>>minishell$ ");
		if (!line)
		 	return (write(1, "!line\n", 6), 0);//OJO ????
		if (line && *line)
			add_history(line);//si tiene contenido, agregamos 'line' al historial
		tokenizer(&tok, line);
		free(line);
	//	init(&cmds, ac, av);//de carlos
	//	builtins(&cmds, env, ac, av);//de carlos
	  	parser(&cmd, tok);
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