#include "minishell.h"

/*Returns the token's len pointed by 'line' if it is a WORD, taking quotes into account*/
int	tok_len(char *line, t_tok **new_tok)
{
	int		len;
	char	c;

	len = 0;
	if (init_operator_type(line, new_tok) == 0)//Inicializa el typo de operador, si lo hay, y a la vez que chequea si no es ningun operador de redir ni un pipe
	{
		while (*(line + len) && (*(line + len) != ' ' && *(line + len)!= '\t' \
		&& *(line + len) != '|' && *(line + len) != '<' \
		&& *(line + len) != '>' && *(line + len) != '\0'))//si es una WORD, busco su len
		{
			if (*(line + len) == '\'' || *(line + len) == '"')//si hay comillas
			{
				c = *(line + len);//inicializo 'c' con el caracter de comilla encontrado
				len++;
				while (*(line + len) && *(line + len) != c)//mientras exista y no sea otra comilla igual a 'c'
					len++;
			}
			if (*(line + len))
				len++;
		}
	}
	return (len);
}