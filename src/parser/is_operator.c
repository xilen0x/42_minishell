/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:57:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:57:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns TRUE if 'node' contains '<', '>', '<<', '>>' or '|' 
or FALSE otherwise.*/

int	is_operator(t_tok *node)
{
	if (node->type == GREATER || node->type == SMALLER \
		|| node->type == D_GREATER || node->type == D_SMALLER \
		|| node->type == PIPE)
		return (TRUE);
	return (FALSE);
}
