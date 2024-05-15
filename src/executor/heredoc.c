# include "minishell.h"

int	heredoc_create(t_cmd *cmd)
{
	char	*tmp_dir;
	int		fd_tmp;
	char	*line;
	t_redir	*aux;

	tmp_dir = ft_strdup("/tmp/heredoc");
	fd_tmp = open(tmp_dir, O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (fd_tmp == -1)
	{
		free(tmp_dir);
		return (1);
	}
	line = readline("> ");
	while (line)
	{
		aux = cmd->redir;
		while (aux && ft_strcmp(line, aux->filename) != 0)
		{
			write(fd_tmp, line, ft_strlen(line));
			free(line);
			line = readline("> ");
			if (!(line))
				break ;
		}
		if (!aux || ft_strcmp(line, aux->filename) == 0)
		{
			free(line);
			close(fd_tmp);
			break ;
		}
	}
	free(tmp_dir);
	close(fd_tmp);
	return (0);
}

/*return 1 if heredoc simbol was found*/
int	heredoc_found(t_cmd *cmd)
{
	t_redir	*aux;

	aux = cmd->redir;
	while (aux)
	{
		if (aux->redir_type == HEREDOC_INPUT)
			return (1);
		aux = aux->next;
	}
	return (0);
}
