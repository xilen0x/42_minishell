/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:01:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/10 10:29:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Reordena los tokens en una nueva lista donde cada pipe es un nodo 
que a su vez contiene un array de comandos-argumentos y una lista 
con las redirecciones. Retorna 0 o 1 si encontro algun error de sintaxis*/
int	parser(t_cmd **cmd, t_tok *tok)
{
	t_cmd	*node;

	node = NULL;
	if (syntax_check_1(tok) == 1)
		return (1);
	if (syntax_check_2(tok) == 1)
		return (1);
	while (tok && tok->type != NULL_TYPE)
	{
		node = cmd_new_node();
		commands_creator(tok, node);
		commands_filler(&tok, node);
		cmd_add_back(cmd, node);
	}
	return (0);
}
