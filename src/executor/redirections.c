# include "minishell.h"

static void	rm_ref_file(t_redir *aux)
{
	while (aux)
	{
		if (aux->redir_type == HEREDOC_INPUT)
		{
			unlink(aux->filename);
		}
		aux = aux->next;
	}
}

int	open_files(t_exe *exe, t_redir *aux)
{
	// (void)exe;
	if (aux->redir_type == REDIR_OUTPUT || aux->redir_type == REDIR_OUTPUT_APPEND)
	{
		if (aux->redir_type == REDIR_OUTPUT_APPEND)
			exe->fd_output = open(aux->filename, O_CREAT | O_WRONLY | O_APPEND, 0660);
		else
			exe->fd_output = open(aux->filename, O_CREAT | O_WRONLY | O_TRUNC, 0660);
		if (exe->fd_output == -1)
			return (1);
		if (dup2(exe->fd_output, STDOUT_FILENO) == -1)
			return (1);
		close(exe->fd_output);
	}
	else if (aux->redir_type == REDIR_INPUT || aux->redir_type == HEREDOC_INPUT)// < || <<
	{
		printf("REDIR_INPUT\n");
		close(exe->fd_input);
	}
	return (0);
}

int	pre_redirections(t_cmd *cmd, t_exe *exe)
{
	t_redir	*aux;

	aux = cmd->redir;
	while (aux)
	{
		if (open_files(exe, aux))
			return (1);
		// rm_ref_file(cmd->redir);
		aux = aux->next;
	}
	if (cmd->next)
	{
		dup2(exe->fd[1], STDOUT_FILENO);
	}
	// close(STDOUT_FILENO);
	close_fd(exe);
	rm_ref_file(cmd->redir);
	return (0);
}


/*check if a redirection operator(>, >>, <, <<) was found*/
int	exist_redirections(t_redir *aux)
{
	if (!aux)
		return (0);
	else
	{
		if (aux->redir_type != NULL_REDIR)
		{
			//printf("REDIRECTION FOUND! %d\n", aux->redir_type);
			return (1);
		}
	}
	return (0);
}
