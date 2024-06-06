#include "minishell.h"

void	control_and_d(char *line)
{
	if (!line)
	{
		if (!isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "exit\n", 5);
		write(STDOUT_FILENO, "exit\n", 5);
		exit(EXIT_SUCCESS);
	}
}

char	*generate_line(void)
{
	char	*line;

	line = readline("minishell$ ");
	if (line && *line)
		add_history(line);
	return (line);
}

static void	main_process(t_env **envlist)
{
	t_tok			*tok;
	t_cmd			*cmd;
	t_exe			exe;
	unsigned int	size_pipe;
	char			*line;

	tok = NULL;
	cmd = NULL;
	line = generate_line();
	control_and_d(line);
	if (!line || !*line)
		return (free(line));
	tokenizer(&tok, line);
	free(line);
//	print_tok(tok);//ELIMINAR ANTES ENTREGA
	if (parser(&cmd, tok) == 1)
		return ;
	tok_free(&tok);
//	print_cmd(cmd);//ELIMINAR ANTES ENTREGA
	should_expand(cmd, *envlist);
//	print_cmd(cmd);//ELIMINAR ANTES ENTREGA
	init_exe(&exe, cmd);
	heredoc(cmd);
	size_pipe = cmd_size(cmd);
	pre_executor(envlist, cmd, &exe, size_pipe);
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
