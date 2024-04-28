#include "minishell.h"

/*Verifica si en el array de comandos o en la lista de 
redirecciones hay algun '$' que debiera ser expandido*/
void	should_expand(t_cmd **cmd, t_env *envlist)
{
	size_t	i;
	t_cmd	*cmd_aux;
	t_redir	*redir_aux;

	cmd_aux = *cmd;
	while (cmd_aux != NULL)
	{
		i = 0;
		while (cmd_aux->command_and_arg[i] != NULL)//recorre la matriz del comando
		{
			if (ft_strchr(cmd_aux->command_and_arg[i], '$') != NULL \
			|| ft_strchr(cmd_aux->command_and_arg[i], '\'') != NULL \
			|| ft_strchr(cmd_aux->command_and_arg[i], '"') != NULL)
			{
				printf("Expansion:\n");
				printf("<%s>\n", cmd_aux->command_and_arg[i]);
				(*cmd)->command_and_arg[i] = expand_and_quote_remove(cmd_aux->command_and_arg[i], envlist);//el res lo envio a la lista original, no al aux
				printf("<%s>\n", (*cmd)->command_and_arg[i]);
				printf("-----------\n");
			}
			i++;
		}
		redir_aux = (*cmd)->redir;//uso un aux temporal para iterar redir (solo para consultar sus variables)
		while (redir_aux != NULL)
		{
			if (ft_strchr(redir_aux->filename, '$') != NULL \
			|| ft_strchr(redir_aux->filename, '\'') != NULL \
			|| ft_strchr(redir_aux->filename, '"') != NULL)
			{
				printf("Expansión:\n");
				printf("<%s>\n", redir_aux->filename);
				(*cmd)->redir->filename = expand_and_quote_remove(redir_aux->filename, envlist);//el res lo envio a la lista original, no al aux
				printf("<%s>\n", (*cmd)->redir->filename);
				printf("-----------\n");
			}
			redir_aux = redir_aux->next;
		}
		cmd_aux = cmd_aux->next;
	}
	printf("\n");//ELIMINAR ANTES DE ENTREGA
}
