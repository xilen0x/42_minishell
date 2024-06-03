/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:30:09 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:30:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----Adds a node to the end of a list t_cmd----*/
void	cmd_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*aux;

	aux = NULL;
	if (*lst)
	{
		aux = cmd_last(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
