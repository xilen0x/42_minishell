/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:22:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:23:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*------Returns a new initialized t_redir node-----*/
t_redir	*redir_new_node(char *str, int redir_type)
{
	t_redir	*node;

	node = (t_redir *)p_malloc(sizeof(t_redir));
	node->fname = str;
	node->redir_type = redir_type;
	node->next = NULL;
	return (node);
}
