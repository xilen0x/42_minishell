/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_operator_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:14:06 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 12:14:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*--Initializes t_tok->type if an operator (<, <<, >, >>, |) is found.--*/
int	init_operator_type(char *line, t_tok **new_tok)
{
	int	flag;

	flag = 1;
	if (*line == '>' && *line == *(line + 1))
		(*new_tok)->type = D_GREATER;
	else if (*line == '<' && *line == *(line + 1))
		(*new_tok)->type = D_SMALLER;
	else if (*line == '>')
		(*new_tok)->type = GREATER;
	else if (*line == '<')
		(*new_tok)->type = SMALLER;
	else if (*line == '|')
		(*new_tok)->type = PIPE;
	else
		flag = 0;
	return (flag);
}
