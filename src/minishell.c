
#include "minishell.h"

static void	control_and_d(char *line)
{
	if (!line)//Ctrl+D cierra el minishell y no seria necesario recoger el exit_status.
	{
   		 if (isatty(STDIN_FILENO))
			write(2, "exit\n", 6);
		// printf("exit\n");//ctrl-D arroja un 'exit' por consola
		 exit(EXIT_SUCCESS);
	}
}

void	minishell(t_env *envlist)
{
	char	*line;
	t_tok	*tok;
	t_cmd	*cmd;
	t_exe	exe;

	tok = NULL;
	cmd = NULL;
	// envlist->tmp_cwd = getenv("OLDPWD");
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
//	print_tok(tok);
	free(line);
	if (parser(&cmd, tok) == 1)
		return ;
	tok_free(&tok);
	should_expand(cmd, envlist);
//	print_cmd(cmd);//ELIMINAR ANTES DE ENTREGA
	init_exe(&exe, cmd);
	heredoc(cmd);
	pre_executor(&envlist, cmd, &exe);
	cmd_free(&cmd);
}
