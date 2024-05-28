
#include "minishell.h"

static void	control_and_d(char *line)
{
	if (!line)
	{
		if (!isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "exit\n", 5);
		write(STDOUT_FILENO, "exit\n", 5);
		exit(EXIT_SUCCESS);
	}
	if (!*line || *line == ' ')
	{
		free(line);
		return ;
	}
}

static void	main_process(t_env **envlist)
{
	t_tok	*tok;
	t_cmd	*cmd;
	char	*line;
	t_exe	exe;

	tok = NULL;
	cmd = NULL;
	line = readline("minishell$ ");
	control_and_d(line);
	if (line && *line)
		add_history(line);
	tokenizer(&tok, line);
	free(line);
	if (parser(&cmd, tok) == 1)
		return ;
	tok_free(&tok);
	should_expand(cmd, *envlist);
	init_exe(&exe, cmd);
	heredoc(cmd);
	pre_executor(envlist, cmd, &exe);
	cmd_free(&cmd);
}

void	minishell(t_env *envlist)
{
	if (isatty(STDIN_FILENO))
		main_process(&envlist);
	else
	{
		write(2, "run ./minishell (without arguments or operators)\n", 49);
		exit(STDERR_FILENO);
	}
}
