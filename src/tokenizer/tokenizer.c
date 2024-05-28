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
			new_tok = tok_new_node(NULL, NULL_TYPE);//malloco node inicialitzat a NULL
			len = tok_len(line + i, &new_tok);//inicializa 'type' si es operador y retorna un 'len' > 0 si es una WORD
			init_word_str(len, new_tok, line, i);//si len > 0, inicializo tok->str con la palabra mallocada y tok->type con el enum 'WORD' 
			if (new_tok->type == D_GREATER || new_tok->type == D_SMALLER)
				len += 2;//por el doble operador
			if (new_tok->type == GREATER || new_tok->type == SMALLER \
			|| new_tok->type == PIPE)
				len += 1;//por el operador simple
			tok_add_back(tok, new_tok);
		}
		i += len;
	}
}