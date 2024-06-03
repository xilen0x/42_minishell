/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:08:22 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/30 12:39:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Allocates memory for an array of strings if any command is found
 on the tok list. Sets to NULL the last element of the array.*/
void	commands_creator(t_tok *tok, t_cmd *node)
{
	size_t	size;

	size = commands_counter(tok);
	if (size > 0)
	{

		node->commands = (char **)p_malloc((size + 1) * sizeof(char *));
		node->commands[size] = NULL;//cierro el array de strings con NULL
	}
}
