/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_word_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:12:41 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 12:13:33 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*If len is bigger than 0, initializes t_tok->str and t_tok->type with 'line'*/
void	init_word_str(size_t len, t_tok *new_tok, char *line, size_t i)
{
	if (len > 0)
	{
		new_tok->str = (char *)p_malloc(sizeof(char) * (len + 1));
		ft_strlcpy(new_tok->str, line + i, len + 1);
		new_tok->type = WORD;
	}
}
