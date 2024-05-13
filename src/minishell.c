
#include "minishell.h"

void	minishell(char *line, t_tok *tok, t_env *envlist, t_cmd *cmd)
{
	t_exe	exe;

	get_signal = 0;//INIT DE VARIABLE GLOBAL
	line = readline(">>>>minishell$ ");
	if (!line)//lo gestinamos aqui, porque el exit_status de Ctrl+D cierra el minishell y no seria necesario recogerlo.
	{
		printf("exit\n");//en el caso del ctrl-D
		exit(EXIT_FAILURE);//SI NECESARIO SE PODRIA GESTIONAR EN ft_msgs y quitar de aqui.
	}
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
	print_cmd(cmd);
	should_expand(cmd, envlist);
	print_cmd(cmd);
//	print_cmd_para_executor(cmd);
	init_exe(&exe, cmd);
	pre_executor(&envlist, cmd, &exe);
	cmd_free(&cmd);
//	return (line);
}
