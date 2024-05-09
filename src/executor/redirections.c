# include "minishell.h"

/*
	NULL_REDIR = 0,          //necesario?
	REDIR_OUTPUT = 3,        //>
	REDIR_INPUT = 4,         //<
	REDIR_OUTPUT_APPEND = 5, //>> 
	HEREDOC_INPUT = 6        //<<
*/

int	redirections(t_cmd *cmd, t_exe *exe)
{
	t_redir	*aux;

	if (cmd->next)
		dup2(exe->fd[1], STDOUT_FILENO);
	close_fd(exe);
	aux = cmd->redir;
	while (aux)
	{
		// if (dup_custom_redirections(exe, aux) == 1)
		// {
		// 	unlink_heredocs(commands->redirect);
		// 	if (out == FT_RETURN)
		// 		return (perror_return(data, 1, aux. ->file));
		// 	else
		// 		perror_exit(data, EXIT_FAILURE, temp->file);
		// }
		printf("teste\n");
		aux = aux->next;
	}
	return (0);
}
