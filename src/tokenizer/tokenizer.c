
#include "minishell.h"

/*Returns the token's len pointed by 'line' if it is WORD, otherwise inits 'key' if it is an operator */
int	tok_len(char *line, t_tok **new_tok)
{
	int		len;
	char	c;

	len = 0;
	if (*line == '>' && *line == *(line + 1))
		(*new_tok)->type = DOUBLE_GREATER;
	else if (*line == '<' && *line == *(line + 1))
		(*new_tok)->type = DOUBLE_SMALLER;		
	else if (*line == '>')
		(*new_tok)->type = GREATER;
	else if (*line == '<')
		(*new_tok)->type = SMALLER;
	else if (*line == '|')
		(*new_tok)->type = PIPE;
	else
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

//'str' siempre sera NULL, excepto si es una WORD que contendra su string
//las comillas se tratan como WORD, si no estan cerradas incluyen hasta el final de la linea
void	tokenizer(t_tok **tok, char *line)
{
	t_tok	*new_tok;
	char	*str_aux;
	size_t	len;
	int		i;

	new_tok = NULL;
	str_aux = NULL;
	len = 0;
	i = 0;
	while (line[i])
	{
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		{
        	i++;
		}
		if (line[i])
		{
			new_tok = tok_new_node(NULL, NULL_TYPE); 
			len = tok_len(line + i, &new_tok);//inicializa 'type' si es operador y retorna 'len' si es WORD
			if (len > 0)
			{
				str_aux = (char *)malloc(sizeof(char) * len + 1);
				malloc_s_pointer_protect(str_aux);//protector del malloc
				ft_strlcpy(str_aux, line + i, len + 1);
				new_tok->str = ft_strdup(str_aux);//OJO esto no es redundante????
				free(str_aux);
				new_tok->type = WORD;
			}
			if (new_tok->type == DOUBLE_GREATER || new_tok->type == DOUBLE_SMALLER)
				len += 2;//por el doble operador
			if (new_tok->type == GREATER || new_tok->type == SMALLER || new_tok->type == PIPE)
				len += 1;//por el operador simple
			tok_add_back(tok, new_tok);
		}
		i += len;
	}
}