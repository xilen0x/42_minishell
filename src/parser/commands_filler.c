/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:16:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/08 15:21:26 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	commands_filler(t_tok **tok, t_cmd *node)
{
	size_t	i;
	char	*tp;

	i = 0;
	while (*tok && (*tok)->type != NULL_TYPE)
    {
        if ((*tok)->type == WORD)
        {
            node->commands[i] = ft_strdup((*tok)->str);
            i++;
            *tok = (*tok)->next;
        }
        else if (is_redirection(*tok) && (*tok)->next->type == WORD)
        {
			tp = ft_strdup((*tok)->next->str);
//            node_redir = redir_new_node(tp, (*tok)->type - 2);
            redir_add_back(&node->redir, redir_new_node(tp, (*tok)->type - 2));
            *tok = (*tok)->next->next;
        }
        else if ((*tok)->type == PIPE)
        {
            *tok = (*tok)->next;
            break;
        }
    }
}


/*
{
	s

	node->commands[*i] = ft_strdup((*tok)->str);
	*tok = (*tok)->next;
	(*i)++;
}*/