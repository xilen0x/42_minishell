/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:05:41 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 11:05:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*--Returns a new node initialized with the arguments--*/
t_tok	*tok_new_node(char *str, int type)
{
	t_tok	*node;

	node = (t_tok *)p_malloc(sizeof(t_tok));
	node->str = str;
	node->type = type;
	node->next = NULL;
	return (node);
}
