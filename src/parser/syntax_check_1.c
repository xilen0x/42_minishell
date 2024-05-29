/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:53:31 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:55:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns '1' if a syntax error on the list is found, otherwise returns 0.*/
int	syntax_check_1(t_tok *tok)
{
	t_tok	*tmp;

	tmp = tok_last(tok);
	if (tok->type == PIPE || tmp->type == PIPE)//SI EMPIEZA O ACABA EN '|'
	{
		handle_error(PRINT_SYNTAX_ERR_1, &tok);
		return (1);
	}
	if (is_operator(tmp))//SI ACABA EN OPERADOR <,>,<<,>>,|
	{
		handle_error(PRINT_SYNTAX_ERR_2, &tok);
		return (1);
	}
	return (0);
}
