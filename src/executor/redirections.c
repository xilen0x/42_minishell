# include "minishell.h"

void	rm_doc(t_redir *aux)
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

int	redirections(t_exe *exe, t_redir *aux)
{
	if (aux->redir_type == REDIR_INPUT || aux->redir_type == HEREDOC_INPUT)// < || <<
	{
		exe->fd_input = open(aux->filename, O_RDONLY);
		if (exe->fd_input < 0)
			return (1);
		dup2(exe->fd_input, STDIN_FILENO);
		close(exe->fd_input);
	}
	else if (aux->redir_type == REDIR_OUTPUT || aux->redir_type == REDIR_OUTPUT_APPEND)
	{
		if (aux->redir_type == REDIR_OUTPUT_APPEND)// >>
			exe->fd_output = open(aux->filename, O_CREAT | O_WRONLY | O_APPEND, 0660);
		else
			exe->fd_output = open(aux->filename, O_CREAT | O_WRONLY | O_TRUNC, 0660);// >
		if (exe->fd_output < 0)
			return (1);
		dup2(exe->fd_output, STDOUT_FILENO);
		close(exe->fd_output);
	}
	return (0);
}

int	pre_redirections(t_cmd *cmd, t_exe *exe)
{
	t_redir	*aux;

	if (cmd->next)
		dup2(exe->fd[1], STDOUT_FILENO);
	close_fd(exe);
	aux = cmd->redir;
	while (aux)
	{
		if (redirections(exe, aux) == 1)
			rm_doc(cmd->redir);
		aux = aux->next;
	}
	rm_doc(cmd->redir);
	return (0);
}
