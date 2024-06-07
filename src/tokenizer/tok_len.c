/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:00:33 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 17:10:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns the token's len pointed by 'line' if it is a WORD and taking quotes
 into account*/
int	tok_len(char *line, t_tok **new_tok)
{
	int		len;
	char	c;

	len = 0;
	if (init_operator_type(line, new_tok) == 0)
	{
		while (*(line + len) && (*(line + len) != ' ' && *(line + len) != '\t' \
		&& *(line + len) != '|' && *(line + len) != '<' \
		&& *(line + len) != '>' && *(line + len) != '\0'))
		{
			if (*(line + len) == '\'' || *(line + len) == '"')
			{
				c = *(line + len);
				len++;
				while (*(line + len) && *(line + len) != c)
					len++;
			}
			if (*(line + len))
				len++;
		}
	}
	return (len);
}
