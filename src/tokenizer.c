
#include "minishell.h"

/*Returns the token's len pointed by 'line' if it is WORD, otherwise inits 'key' if it is an operator */
int	tok_len(char *line, t_tok **new_tok)
{
	int		len;
	char	c;

	len = 0;
	if (*line == '>' && *line == *(line + 1))
		(*new_tok)->key = D_GREATER;
	else if (*line == '<' && *line == *(line + 1))
		(*new_tok)->key = D_SMALLER;		
	else if (*line == '>')
		(*new_tok)->key = GREATER;
	else if (*line == '<')
		(*new_tok)->key = SMALLER;
	else if (*line == '|')
		(*new_tok)->key = PIPE;
	else
	{
		while (*(line + len) && (*(line + len) != ' ' && *(line + len)!= '\t' \
		&& *(line + len) != '|' && *(line + len) != '<' \
		&& *(line + len) != '>' && *(line + len) != '\0'))//si es una WORD, busco su len
		{
			if (*(line + len) == '\'' || *(line + len) == '"')
			{
				c = *(line + len);//inicializo 'c' con el caracter de comilla encontrado
				len++;
				while (*(line + len) && *(line + len) != c)//mientras exista y no sea otra comilla
					len++;
			}
			if (*(line + len))
			len++;
		}
	}
	return (len);
}

/*------------TOKENIZADOR------------*/
//'val' siempre sera NULL excepto si es una WORD que contendra su string
//las comillas se tratan como WORD, si no estan cerradas incluyen hasta el final de la linea
void	tokenizer(t_tok *tok, char *line)
{
	t_tok	*new_tok;
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	new_tok = NULL;
	//----OBTENDRA EL STRING PARA CADA TOKEN HASTA LLEGAR AL FINAL DE 'line'--------
	while (line[i])
	{
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        	i++;
		if (line[i])
		{
			new_tok = tok_new_node(NULL, NULL_KEY); 
			len = tok_len(line + i, &new_tok);//inicializa 'key' si es operador y retorna 'len' si es WORD
			if (len > 0)
			{
				//-----ASIGNA MEMORIA Y LA RELLENA CON EL STRING-------- 
				str = (char *)malloc(sizeof(char) * len + 1);
				if (!str)
					return ;//gestionar error ???
				str_l_cpy(str, line + i, len + 1);
				new_tok->val = ft_strdup(str);
				free(str);
				new_tok->key = WORD;
			}
			if (new_tok->key == D_GREATER || new_tok->key == D_SMALLER)
				len += 2;//por el doble operador
			if (new_tok->key == GREATER || new_tok->key == SMALLER || new_tok->key == PIPE)
				len += 1;//por el operador simple
			tok_add_back(&tok, new_tok);
		}
		i += len;
	}
	tok_print(tok);//ELIMINAR AL ENTREGAR
//	lstclear(&tok);
}
