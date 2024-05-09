
#include "minishell.h"

char	*from_readline(char	*line, t_tok	*tok, t_env	*envlist, t_cmd	*cmd)
{
	t_exe	exe;

	line = readline(">>>>minishell$ ");
	if (!line)
	{
		printf("exit\n");//en el caso del ctrl-D
		printf(WHITE);
		exit(0);
	}
	if (line && *line)
		add_history(line);
	if (!*line || *line == ' ')
	{
		free(line);
		return (0);
	}
	tokenizer(&tok, line);
	free(line);
	parser(&cmd, tok);
	tok_free(&tok);
	//should_expand(cmd, envlist, &exit_status);
	init_exe(&exe, cmd);
	pre_executor(&envlist, cmd, &exe);
	cmd_free(&cmd);
	return (line);
}
