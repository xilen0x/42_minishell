/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:26:33 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:58 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*------Returns a new NULL initialized t_cmd node-----*/
t_cmd	*cmd_new_node(void)
{
	t_cmd	*node;

	node = (t_cmd *)p_malloc(sizeof(t_cmd));
	node->commands = NULL;
	node->redir = NULL;
	node->next = NULL;
	return (node);
}
