#include "minishell.h"

/*Verifica si en el array de comandos o en la lista de 
redirecciones hay alguna comilla simple, doble o '$' que debiera ser expandido*/
void	should_expand(t_cmd *cmd, t_env *envlist, unsigned int *exit_status )
{
	size_t	i;
//	char	*cmd_tmp;
	// char	*redir_tmp;
//	t_cmd	*cmd_aux;
//	t_redir	*redir_aux;

//	cmd_aux = *cmd;
//	redir_aux = NULL;
//	while (cmd_aux != NULL)
	while (cmd)
	{
		i = 0;

		while ((cmd)->command_and_arg[i] != NULL)//recorre el array de strings de los comandos
		{
			if (ft_strchr((cmd)->command_and_arg[i], '$') != NULL \
			|| ft_strchr((cmd)->command_and_arg[i], '\'') != NULL \
			|| ft_strchr((cmd)->command_and_arg[i], '"') != NULL)
			{
				printf("Expansion:\n");
				printf("<%s>\n", (cmd)->command_and_arg[i]);

				(cmd)->command_and_arg[i] = expand_and_quote_remove((cmd)->command_and_arg[i], envlist, exit_status);//el res lo envio a la lista original, no al aux				free((cmd)->command_and_arg[i]);
				// free((cmd)->command_and_arg[i]);
//				(cmd)->command_and_arg[i] = cmd_tmp;

				printf("<%s>\n", (cmd)->command_and_arg[i]);
				printf("-----------\n");
			}
			i++;
		}

		// while ((cmd)->redir != NULL)//recorre lista redir buscando, '\'' '"' '$'
		// {
		// 	if (ft_strchr((cmd)->redir->filename, '$') != NULL \
		// 	|| ft_strchr((cmd)->redir->filename, '\'') != NULL \
		// 	|| ft_strchr((cmd)->redir->filename, '"') != NULL)
		// 	{
		// 		printf("Expansión:\n");
		// 		printf("<%s>\n", (cmd)->redir->filename);

		// 		redir_tmp = expand_and_quote_remove((cmd)->redir->filename, envlist, exit_status);//el res lo envio a la lista original, no al aux
		// 		free((cmd)->redir->filename);
		// 		(cmd)->redir->filename = redir_tmp;

		// 		printf("<%s>\n", (cmd)->redir->filename);
		// 		printf("-----------\n");
		// 	}
		// 	(cmd)->redir = (cmd)->redir->next;
		// }
		(cmd) = (cmd)->next;
	}
	printf("\n");//ELIMINAR ANTES DE ENTREGA
}
