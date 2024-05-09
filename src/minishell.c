
#include "minishell.h"

char	*minishell(char *line, t_tok *tok, t_env *envlist, t_cmd *cmd)
{
	t_exe	*exe;

	line = readline(">>>>minishell$ ");
	if (!line)
	{
		printf("exit\n");//en el caso del ctrl-D
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
	init_exe(exe, cmd);
	should_expand(cmd, envlist, exe);
	executor(&envlist, cmd);
	cmd_free(&cmd);
	return (line);
}
