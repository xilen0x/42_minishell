
#include "minishell.h"

static int	init_operator_type(char *line, t_tok **new_tok)
{
	int	flag;

	flag = 1;
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
		flag = 0;
	return (flag);
}



/*Returns the token's len pointed by 'line' if it is a WORD, otherwise inits 'type' if it is an operator */
int	tok_len(char *line, t_tok **new_tok)
{
	int		len;
	char	c;

	len = 0;
	if (init_operator_type(line, new_tok) == 0)//si no es ningun operador de redir ni un pipe

//	if (*line == '>' && *line == *(line + 1))
//		(*new_tok)->type = DOUBLE_GREATER;
//	else if (*line == '<' && *line == *(line + 1))
//		(*new_tok)->type = DOUBLE_SMALLER;		
//	else if (*line == '>')
//		(*new_tok)->type = GREATER;
//	else if (*line == '<')
//		(*new_tok)->type = SMALLER;
//	else if (*line == '|')
//		(*new_tok)->type = PIPE;
//	else
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

//Tokeniza la 'line' sea cual sea, sin verificar errores sintacticos (separa por ' ', \t, <, >, >>, <<, |)
//'str' siempre sera NULL, excepto si es una WORD que contendra su string
//las comillas se tratan como WORD y si no estan cerradas llegaran hasta fin de linea
void	tokenizer(t_tok **tok, char *line)
{
	t_tok	*new_tok;
	size_t	len;
	int		i;

	new_tok = NULL;
	i = 0;
	while (line && line[i])
	{
		len = 0;
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		{
        	i++;
		}
		if (line[i])
		{
			new_tok = tok_new_node(NULL, NULL_TYPE);//malloco node inicialitzat a NULL
			len = tok_len(line + i, &new_tok);//inicializa 'type' si es operador y retorna un 'len' > 0 si es una WORD
			if (len > 0)
			{
				new_tok->str = (char *)p_malloc(sizeof(char) * (len + 1));//malloco *str dentro del nodo
				ft_strlcpy(new_tok->str, line + i, len + 1);
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
