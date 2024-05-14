
#include "minishell.h"

static void	control_and_d(char *line)
{
	if (!line)//Ctrl+D cierra el minishell y no seria necesario recoger el exit_status.
	{
		printf("exit\n");//ctrl-D arroja un 'exit' por consola
		exit(EXIT_FAILURE);
	}
}

void	minishell(char *line, t_env *envlist)
{
	t_tok	*tok;
	t_cmd	*cmd;
	t_exe	exe;

	get_signal = 0;//INIT DE VARIABLE GLOBAL
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
	parser(&cmd, tok);
	tok_free(&tok);
	should_expand(cmd, envlist);
	print_cmd(cmd);
	init_exe(&exe, cmd);
	pre_executor(&envlist, cmd, &exe);
	cmd_free(&cmd);
}
