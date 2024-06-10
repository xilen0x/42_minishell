/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:57:51 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 17:02:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*------FREES t_tok list AND PRINTS AN ERROR MESSAGE-----*/
void	handle_error(char *str, t_tok **tok)
{
	write(2, str, ft_strlen(str));
	set_exit_status(2);
	if (tok != NULL)
		tok_free(tok);
}
