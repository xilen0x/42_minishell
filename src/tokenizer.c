
#include "minishell.h"

/*-----Returns the token's len pointed by 'line' */
/*INICIALIZA valor de 'key' del nodo y retorna un len > 0 si 'key' = WORD*/
int	tok_len(char *line, t_lst **new_tok)//args: puntero a inicio del token en 'line', un doble puntero al nodo
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
	{//si es un WORD, con o sin comillas, busco el len
		while (*(line + len) && (*(line + len) != ' ' && *(line + len)!= '\t' \
		&& *(line + len) != '|' && *(line + len) != '<' \
		&& *(line + len) != '>' && *(line + len) != '\0'))
		{
			if (*(line + len) == '\'' || *(line + len) == '"')
			{
				c = *(line + len);//inicializo 'c' con el caracter comilla encontrado
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
//EL 'val' DE TODOS LOS NODOS SERA NULL, EXCEPTO LOS DE key=WORD
//las comillas se tratan como una WORD, si no estan cerradas incluyen hasta el final de la linea
void	tokenizer(t_lst *tokens, char *line)
{
	t_lst	*new_tok;//nodo con cada token
	char	*str;//el str que contendrá el token antes de meterlo en el nodo
	size_t	len;//la len del str de cada token
	int		i;

	i = 0;
	len = 0;
	new_tok = NULL;
	//----OBTENDRA EL STRING DE CADA TOKEN HASTA LLEGAR AL FINAL DE 'line'--------
	while (line[i])
	{
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        	i++;
		if (line[i])
		{
			new_tok = lst_new_node(NULL, NULL_KEY);//creo un nodo y lo inicializo todo a 0 
			len = tok_len(line + i, &new_tok);//INICIALIZA EL key si es operador y retorna el len si es una WORD
			if (len > 0)//si contiene algo, es una WORD y la INICIALIZO su string en 'val'
			{
				//-----ASIGNA MEMORIA Y LA RELLENA CON EL STRING-------- 
				str = (char *)malloc(sizeof(char) * len + 1);
				if (!str)
					return ;//gestionar error, liberar y cerrar programa, quizas con 'exit'
				str_l_cpy(str, line + i, len + 1);//rellenamos str con strlcpy(*src, *dst, dst_size)
				new_tok->val = ft_strdup(str);//INICIALIZA el 'val' del NODO si es una WORD......deberia hacer new_tok->val = strdup(str) y luego free(str)
				free(str);//libero para poderlo usar en la siguiente iteracion
				new_tok->key = WORD;
			}
			if (new_tok->key == D_GREATER || new_tok->key == D_SMALLER)
				len += 2;//por el doble operador
			if (new_tok->key == GREATER || new_tok->key == SMALLER || new_tok->key == PIPE)
				len += 1;;//por el operador simple
			lst_add_back(&tokens, new_tok);
		}
		i += len;
	}
	lst_print(tokens);//ELIMINAR AL ENTREGAR
//	lstclear(&tokens);
}
