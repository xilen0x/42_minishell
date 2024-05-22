# include "minishell.h"

int	heredoc_create(t_redir *redir, int hd_nbr)
{
	char	*tmp_dir;
	int		fd_tmp;
	char	*line;

	tmp_dir = ft_strjoin("/tmp/heredoc", ft_itoa(hd_nbr));
	fd_tmp = open(tmp_dir, O_CREAT | O_WRONLY | O_TRUNC, 0660);
	line = readline("> ");
	while (line && ft_strcmp(line, redir->filename) != 0)
	{
		write(fd_tmp, line, ft_strlen(line));
		write(fd_tmp, "\n", 1);
		free(line);
		line = readline("> ");
	}
	close(fd_tmp);
	free(line);
	free(redir->filename);
	redir->filename = ft_strdup(tmp_dir);
	free(tmp_dir);
	hd_nbr--;
	set_signals(PARENT);
	return (0);
}

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

/*return 1 if heredoc simbol was found*/
// int	heredoc_found(t_cmd *cmd)
// {
// 	t_redir	*aux;

// 	aux = cmd->redir;
// 	while (aux)
// 	{
// 		if (aux->redir_type == HEREDOC_INPUT)
// 			return (1);
// 		aux = aux->next;
// 	}
// 	return (0);
// }
