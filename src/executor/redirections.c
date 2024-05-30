/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:41 by castorga          #+#    #+#             */
/*   Updated: 2024/05/30 12:28:35 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*opens files for redirections and duplicates file descriptors,
 returning 1 on error.*/
int	open_files(t_exe *exe, t_redir *aux)
{
	if (aux->redir_type == REDIR_INPUT || aux->redir_type == HEREDOC_INPUT)
	{
		exe->fd_input = open(aux->fname, O_RDONLY);
		if (exe->fd_input == -1)
			return (1);
		if (dup2(exe->fd_input, STDIN_FILENO) == -1)
			return (1);
		close(exe->fd_input);
	}
	else if (aux->redir_type == REDIR_OUTPUT || \
			aux->redir_type == REDIR_OUTPUT_APPEND)
	{
		if (aux->redir_type == REDIR_OUTPUT_APPEND)
			exe->fd_output = open(aux->filename, O_CREAT | \
												O_WRONLY | O_APPEND, 0660);
		else
			exe->fd_output = open(aux->filename, O_CREAT | \
												O_WRONLY | O_TRUNC, 0660);
		if (exe->fd_output == -1)
			return (1);
		if (dup2(exe->fd_output, STDOUT_FILENO) == -1)
			return (1);
		close(exe->fd_output);
	}
	return (0);
}

/* sets up file descriptors for command redirections and 
returns 1 if a file opening error occurs.*/
int	pre_redirections(t_cmd *cmd, t_exe *exe)
{
	t_redir	*aux;

	aux = cmd->redir;
	if (cmd->next != NULL)
	{
		dup2(exe->fd[1], STDOUT_FILENO);
	}
	while (aux)
	{
		if (open_files(exe, aux) == 1)
		{
			if (aux->redir_type == HEREDOC_INPUT)
			{
				unlink(aux->fname);
			}
			return (1);
		}
		aux = aux->next;
	}
	return (0);
}


/*check if a redirection operator(>, >>, <, <<) was found*/
int	exist_redirections(t_cmd *cmd)
{
	t_redir			*aux;

	aux = cmd->redir;
	if (!aux)
		return (0);
	else
	{
		if (aux->redir_type != NULL_REDIR)
			return (1);
	}
	return (0);
}
