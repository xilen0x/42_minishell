/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:47:24 by castorga          #+#    #+#             */
/*   Updated: 2024/05/28 10:47:27 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*creates a temp file to store the content of the heredoc until the delimiter
 is encountered.*/
int	heredoc_create(t_redir *redir, int hd_nbr)
{
	char	*tmp_dir;
	int		fd_tmp;
	char	*line;

	tmp_dir = ft_strjoin("/tmp/heredoc", ft_itoa(hd_nbr));
	fd_tmp = open(tmp_dir, O_CREAT | O_WRONLY | O_TRUNC, 0660);
	line = readline("> ");
	while (line && ft_strcmp(line, redir->fname) != 0)
	{
		write(fd_tmp, line, ft_strlen(line));
		write(fd_tmp, "\n", 1);
		free(line);
		line = readline("> ");
	}
	set_signals(CHILD);
	close(fd_tmp);
	free(line);
	free(redir->fname);
	redir->fname = ft_strdup(tmp_dir);
	free(tmp_dir);
	hd_nbr--;
	set_signals(PARENT);
	return (0);
}

/*iterates commands and calls heredoc_create for each << found.*/
int	heredoc(t_cmd *cmd)
{
	t_redir	*aux;
	int		hd_nbr;

	hd_nbr = 0;
	while (cmd)
	{
		aux = cmd->redir;
		while (aux)
		{
			if (aux->redir_type == HEREDOC_INPUT)
			{
				heredoc_create(aux, hd_nbr);
				hd_nbr++;
			}
			aux = aux->next;
		}
		cmd = cmd->next;
	}
	return (0);
}
