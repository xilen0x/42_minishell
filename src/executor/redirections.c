# include "minishell.h"

// static void	rm_ref_file(t_redir *aux)
// {
// 	while (aux)
// 	{
// 		if (aux->redir_type == HEREDOC_INPUT)
// 		{
// 			unlink(aux->filename);
// 		}
// 		aux = aux->next;
// 	}
// }

int	open_files(t_exe *exe, t_redir *aux)
{
	//if (aux->redir_type == REDIR_INPUT || aux->redir_type == HEREDOC_INPUT)// < || <<
	if (aux->redir_type == REDIR_INPUT)
	{
		exe->fd_input = open(aux->filename, O_RDONLY);
		if (exe->fd_input == -1)
			return (1);
		if (dup2(exe->fd_input, STDIN_FILENO) == -1)
			return (1);
		close(exe->fd_input);
	}
	else if (aux->redir_type == REDIR_OUTPUT || aux->redir_type == REDIR_OUTPUT_APPEND)// > || >>
	{
		if (aux->redir_type == REDIR_OUTPUT_APPEND)// >>
			exe->fd_output = open(aux->filename, O_CREAT | O_WRONLY | O_APPEND, 0660);
		else
			exe->fd_output = open(aux->filename, O_CREAT | O_WRONLY | O_TRUNC, 0660);
		if (exe->fd_output == -1)
			return (1);
		if (dup2(exe->fd_output, STDOUT_FILENO) == -1)
			return (1);
		close(exe->fd_output);
	}
	return (0);
}

int	pre_redirections(t_cmd *cmd, t_exe *exe)
{
	t_redir	*aux;

	aux = cmd->redir;
	if (cmd->next)
	{
		dup2(exe->fd[1], STDOUT_FILENO);
	}
	close_fd(exe);
	while (aux)
	{
		if (open_files(exe, aux))
		{
			if (aux->redir_type == HEREDOC_INPUT)
			{
				unlink(aux->filename);
			}
			return (1);
		}
		aux = aux->next;
	}
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
			return (1);
	}
	free(aux);
	return (0);
}
