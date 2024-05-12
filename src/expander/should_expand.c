#include "minishell.h"

/*Look for any expandable or quote removable token into 'cmd' list*/
void	should_expand(t_cmd *cmd, t_env *envlist)
{
	size_t	i;
	char	*redir_tmp;

	while (cmd)
	{
		i = 0;
		while (cmd->commands[i] != NULL)//recorre el array de strings de los comandos buscando algo que expandir
		{
			if (ft_strchr(cmd->commands[i], '$') != NULL \
			|| ft_strchr(cmd->commands[i], '\'') != NULL \
			|| ft_strchr(cmd->commands[i], '"') != NULL)
			{
//				printf("Expansion:\n");
//				printf("<%s>\n", cmd->commands[i]);
				cmd->commands[i] = expand_quote_rm(cmd->commands[i], envlist);
//				printf("<%s>\n", cmd->commands[i]);
//				printf("-----------\n");
			}
			i++;
		}
		 while (cmd->redir != NULL)//recorre lista redir buscando '\'' '"' '$' para expandir
		 {
		 	if (ft_strchr(cmd->redir->filename, '$') != NULL \
		 	|| ft_strchr(cmd->redir->filename, '\'') != NULL \
		 	|| ft_strchr(cmd->redir->filename, '"') != NULL)
		 	{
//		 		printf("Expansión:\n");
//		 		printf("<%s>\n", cmd->redir->filename);
	 			redir_tmp = expand_quote_rm(cmd->redir->filename, envlist);
//		 		free(cmd->redir->filename);YA SE LIBERO EN new_tok_builder
		 		cmd->redir->filename = redir_tmp;
//	 			printf("<%s>\n", cmd->redir->filename);
//		 		printf("-----------\n");
		 	}
		 	cmd->redir = cmd->redir->next;
		 }
		cmd = cmd->next;
	}
	//printf("\n");//ELIMINAR ANTES DE ENTREGA
}
