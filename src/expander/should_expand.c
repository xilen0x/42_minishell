#include "minishell.h"

/*Look for any expandable or quote removable token into 'cmd' list*/
void	should_expand(t_cmd *cmd, t_env *envlist)
{
	size_t	i;
	t_cmd	*cmd_aux;//para recorrer lista redir sin perder la cabeza de lista
	t_redir	*redir_aux;//para recorrer lista redir sin perder la cabeza de lista
	char	*redir_tmp;

	cmd_aux = cmd;
	redir_aux = cmd->redir;
	while (cmd_aux)
	{
		i = 0;
		while (cmd_aux->commands[i] != NULL)//recorre el array de strings de los comandos buscando algo que expandir
		{
			if (ft_strchr(cmd_aux->commands[i], '$') != NULL \
			|| ft_strchr(cmd_aux->commands[i], '\'') != NULL \
			|| ft_strchr(cmd_aux->commands[i], '"') != NULL)
			{
//				printf("Expansion:\n");
//				printf("<%s>\n", cmd->commands[i]);
				cmd_aux->commands[i] = expand_quote_rm(cmd_aux->commands[i], envlist);
//				printf("<%s>\n", cmd->commands[i]);
//				printf("-----------\n");
			}
			i++;
		}
//		redir_aux = cmd->redir;
		while (redir_aux)//recorre lista redir buscando '\'' '"' '$' para expandir
		{
		 	if (ft_strchr(redir_aux->filename, '$') != NULL \
		 	|| ft_strchr(redir_aux->filename, '\'') != NULL \
		 	|| ft_strchr(redir_aux->filename, '"') != NULL)
		 	{
//		 		printf("Expansión:\n");
//		 		printf("<%s>\n", cmd->redir->filename);
	 			redir_tmp = expand_quote_rm(redir_aux->filename, envlist);
//		 		free(cmd->redir->filename);YA SE LIBERO EN new_tok_builder
		 		redir_aux->filename = redir_tmp;
//	 			printf("<%s>\n", cmd->redir->filename);
//		 		printf("-----------\n");
		 	}
		 	redir_aux = redir_aux->next;
		}
		cmd_aux = cmd_aux->next;
	}
}
