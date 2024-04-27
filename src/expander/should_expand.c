#include "minishell.h"

/*Verifica si en el array de comandos o en la lista de 
redirecciones hay algun '$' que debiera ser expandido*/
void	should_expand(t_cmd **cmd, t_env *envlist)
{
	size_t	i;
//	size_t	j = 0;//ELIMINAR ANTES DE ENTREGA
	t_cmd	*cmd_aux;
	t_redir	*redir_aux;

	cmd_aux = *cmd;
	while (cmd_aux != NULL)//uso un aux temporal para iterar cmd
	{
		i = 1;//porque el indice 0 es el commando y este no deberia tener '$'(a menos que sea literal' ' y no seria buena practica)
		while (cmd_aux->command_and_arg[i] != NULL)//recorre la matriz del comando
		{
			if (ft_strchr(cmd_aux->command_and_arg[i], '$') != NULL \
			|| ft_strchr(cmd_aux->command_and_arg[i], '\'') != NULL \
			|| ft_strchr(cmd_aux->command_and_arg[i], '"') != NULL)//si encuentra un '$' '\" '\''
			{
				printf("visto '$' o comilla en indice %zu de command\n", i);//ELIMINAR ANTES DE ENTREGA
				(*cmd)->command_and_arg[i] = expand_and_quote_remove(cmd_aux->command_and_arg[i], envlist);//el res lo envio a la lista original, no al aux
				printf("token final <%s>\n", (*cmd)->command_and_arg[i]);
			}
			i++;
		}
		redir_aux = (*cmd)->redir;//uso un aux temporal para iterar redir (solo para consultar sus variables)
		while (redir_aux != NULL)//recorre la lista redir
		{
			if (ft_strchr(redir_aux->filename, '$') != NULL \
			|| ft_strchr(redir_aux->filename, '\'') != NULL \
			|| ft_strchr(redir_aux->filename, '"') != NULL)
			{
				printf("visto '$' o comilla en t_redir\n");//ELIMINAR ANTES DE ENTREGA
				(*cmd)->redir->filename = expand_and_quote_remove(redir_aux->filename, envlist);//el res lo envio a la lista original, no al aux
				printf("token final <%s>\n", (*cmd)->redir->filename);
			}
			redir_aux = redir_aux->next;
		}
		cmd_aux = cmd_aux->next;
	}
	printf("\n");//ELIMINAR ANTES DE ENTREGA
}
//SI NO HAY CIERRE DE COMILLAS lo gestionaré como => syntax error near token 'print_del_token'???
