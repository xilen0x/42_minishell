
#include "minishell.h"

static void	control_and_d(char *line)
{
	if (!line)//Ctrl+D cierra el minishell y no seria necesario recoger el exit_status.
	{
		// write(2, "exit\n", 5);//ctrl-D arroja un 'exit' por consola
		exit(EXIT_SUCCESS);
	}
}

void	minishell(t_env *envlist)
{
	char	*line;
	t_tok	*tok;
	t_cmd	*cmd;
	t_exe	exe;

	get_signal = 0;//VAR GLOBAL
	tok = NULL;
	cmd = NULL;
	line = readline(">>>>minishell$ ");
	control_and_d(line);
	if (line && *line)
		add_history(line);
	if (!*line || *line == ' ')
	{
		free(line);
		return ;
	}
	tokenizer(&tok, line);
	free(line);
	if (parser(&cmd, tok) == 1)
		return ;
	tok_free(&tok);
	should_expand(cmd, envlist);
	// print_cmd(cmd);//ELIMINAR ANTES DE ENTREGA
	init_exe(&exe, cmd);
	pre_executor(&envlist, cmd, &exe);
	cmd_free(&cmd);
}
