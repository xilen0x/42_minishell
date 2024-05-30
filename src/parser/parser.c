/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:01:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/30 12:03:32 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Reordena los tokens en una nueva lista donde cada pipe es un nodo 
que a su vez contiene un array de comandos-argumentos y una lista 
con las redirecciones. Retorna 0 o 1 si encontro algun error de sintaxis*/
//RENOMBRAR EN INGLES<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int	parser(t_cmd **cmd, t_tok *tok)
{
	t_cmd   *node;
//    t_tok   *tmp;//Creo que puedo prescindir de este tmp y hacerlo todo con tok
    size_t  i;//itera los comandos
//    size_t  size;
	char	*str_duplicate;
    t_redir *node_redir;//si l'elimino m'estalvio 3 lines

    node = NULL;
//    tmp = NULL;
//   size = 0;
    node_redir = NULL;
    if (syntax_check_1(tok) == 1)
        return (1);
    if (syntax_check_2(tok) == 1)
        return (1);
 //   tmp = tok;
    while (tok && tok->type != NULL_TYPE)//<<<CREA LISTA t_cmd CON CADA PIPE>>>. Es necesario NULL_TYPE?
    {
        i = 0;        
        node = cmd_new_node();//crea un nodo t_cmd mallocado con todos sus elementos a NULL

		commands_creator(tok, node);//<<<NEW>>>reduim aqui les 3 lineas de sota

//        size = commands_counter(tok);//averigua el size que debera tener el array de commands
//        if (size > 0)//solo se malloca **commands si existe algun comando, sino es NULL 
//            node->commands = (char **)p_malloc((size + 1) * sizeof(char *));


         while (tok && tok->type != NULL_TYPE)//Inicializa el nodo t_cmd con el pipe actual
        {
            if (tok->type == WORD)//FUNCIO EXTERNA, HAURE DE PASAR-LI: 'i', 'node', 'tok'
            {
                node->commands[i] = ft_strdup(tok->str);//duplica la WORD y la mete en **commands
                i++;
//                if (i == size)//cierro el array con NULL si es el ultimo elemento
//                    node->commands[i] = NULL;
                tok = tok->next;
            }
            else if (is_redirection(tok) && tok->next->type == WORD)//SOLO SI ES REDIRECCION Y NEXT ES WORD SE CREA LISTA 'redir'
            {
				str_duplicate = ft_strdup(tok->next->str);
                node_redir = redir_new_node(str_duplicate, tok->type - 2);//crea e inicializa node t_redir
                redir_add_back(&node->redir, node_redir);
                tok = tok->next->next;//salto dos nodos de tok (operador + key)
            }
            else if (tok->type == PIPE)
            {
                tok = tok->next;
                break;
            }
        }
        cmd_add_back(cmd, node);
    }
    return (0);
}