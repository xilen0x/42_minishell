/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:56:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns TRUE if 'node' contains '<', '>', '<<', '>>' and FALSE otherwise.*/

int	is_redirection(t_tok *node)
{
	if (node->type == GREATER || node->type == SMALLER \
		|| node->type == D_GREATER || node->type == D_SMALLER)
		return (TRUE);
	return (FALSE);
}
