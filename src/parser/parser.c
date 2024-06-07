/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:01:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 17:04:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Reordena los tokens en una nueva lista donde cada pipe es un nodo 
que a su vez contiene un array de comandos-argumentos y una lista 
con las redirecciones. Retorna 0 o 1 si encontro algun error de sintaxis*/
int	parser(t_cmd **cmd, t_tok *tok)
{
	t_cmd	*node;
    size_t  i;
	char	*str_duplicate;
    t_redir *node_redir;

    node = NULL;
    node_redir = NULL;
    if (syntax_check_1(tok) == 1)
        return (1);
    if (syntax_check_2(tok) == 1)
        return (1);
    while (tok && tok->type != NULL_TYPE)
    {
        i = 0;        
        node = cmd_new_node();

		commands_creator(tok, node);
         while (tok && tok->type != NULL_TYPE)
        {
            if (tok->type == WORD)
            {
                node->commands[i] = ft_strdup(tok->str);
                i++;
                tok = tok->next;
            }
            else if (is_redirection(tok) && tok->next->type == WORD)
            {
				str_duplicate = ft_strdup(tok->next->str);
                node_redir = redir_new_node(str_duplicate, tok->type - 2);
                redir_add_back(&node->redir, node_redir);
                tok = tok->next->next;
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
