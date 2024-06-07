/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:09:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 17:22:51 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Tokenizes the content of 'line' using delimiters (' ', \t, <, >, >>, <<, |) \
and put them on a 'tok' list. Each node contains tok->type and tok->str if it\
 is not an operator. The function does not check for syntax errors.
If unclosed quotes are found they are closed at the end of the line.*/

void	tokenizer(t_tok **tok, char *line)
{
	t_tok	*new_tok;
	size_t	len;
	size_t	i;	

	new_tok = NULL;
	i = 0;
	while (line && line[i])
	{
		len = 0;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i])
		{
			new_tok = tok_new_node(NULL, NULL_TYPE);
			len = tok_len(line + i, &new_tok);
			init_word_str(len, new_tok, line, i);
			if (new_tok->type == D_GREATER || new_tok->type == D_SMALLER)
				len += 2;
			if (new_tok->type == GREATER || new_tok->type == SMALLER \
			|| new_tok->type == PIPE)
				len += 1;
			tok_add_back(tok, new_tok);
		}
		i += len;
	}
}
