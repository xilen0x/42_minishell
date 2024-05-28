#include "minishell.h"

/* Look for any expandable or quote removable token into 'cmd' list */
void	should_expand(t_cmd *cmd, t_env *envlist)
{
	size_t	i;
	t_cmd	*cmd_aux;
	t_redir	*redir_aux;
//	char	*redir_tmp;

	cmd_aux = cmd;
	redir_aux = cmd->redir;
	while (cmd_aux)
	{
		i = 0;
		while (cmd_aux->commands && cmd_aux->commands[i])//busca $, ', " en los comandos
		{
			if (ft_strchr(cmd_aux->commands[i], '$') != NULL ||
				ft_strchr(cmd_aux->commands[i], '\'') != NULL ||
				ft_strchr(cmd_aux->commands[i], '"') != NULL)
				cmd_aux->commands[i] = expand_quote_rm(cmd_aux->commands[i], envlist);
			i++;
		}
		while (redir_aux)//busca ', ", $ en las redirecciones
		{
		 	if (ft_strchr(redir_aux->fname, '$') != NULL ||
				ft_strchr(redir_aux->fname, '\'') != NULL ||
				ft_strchr(redir_aux->fname, '"') != NULL)
//		 	{
//	 			redir_tmp = expand_quote_rm(redir_aux->filename, envlist);
//		 		redir_aux->filename = redir_tmp;
//		 	}
				redir_aux->fname = expand_quote_rm(redir_aux->fname, envlist);
		 	redir_aux = redir_aux->next;
		}
		cmd_aux = cmd_aux->next;
	}
}