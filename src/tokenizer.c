
#include "minishell.h"

/*-----Returns the len of the first token found in 'line' */
/*INICIALIZA valor de 'keyword' del nodo y retorna un len > 0 si 'keyword' = WORD*/
int	tok_len(char *line, t_lst **new_tok)//args: puntero a inicio del token en 'line', un doble puntero al nodo
{
	int		len;
	char	c;

	len = 0;
//	c = '\0';
	if (*line == '>' && *line == *(line + 1))
		(*new_tok)->keyword = DOUBLE_GREATER;
	else if (*line == '<' && *line == *(line + 1))
		(*new_tok)->keyword = DOUBLE_SMALLER;		
	else if (*line == '>')
		(*new_tok)->keyword = GREATER;
	else if (*line == '<')
		(*new_tok)->keyword = SMALLER;
	else if (*line == '|')
		(*new_tok)->keyword = PIPE;
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
//			if (*(line + len))
			len++;
		}
	}
	return (len);
}

/*------------TOKENIZADOR------------*/
//EL 'value' DE TODOS LOS NODOS SERA NULL, EXCEPTO LOS DE keyword=WORD
void	tokenizer(t_lst *tokens, char *line)
{
	t_lst	*new_tok;//nodo con cada token
	char	*str;//el str que contendrá el token antes de meterlo en el nodo
	size_t	len;//la len del str del token
	int		i;//guardará el indice donde estamos en el recorrido por 'line'

	i = 0;
	len = 0;
	new_tok = NULL;
	//----OBTENDRA EL STRING DE CADA TOKEN HASTA LLEGAR AL FINAL DE 'line'--------
	while (line[i])
	{
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		{
        	i++;
		}
		if (line[i])
		{
			new_tok = lstnew_node(NULL, NULL_KEY);//creo un nodo y lo inicializo todo a 0 
			len = tok_len(line + i, &new_tok);//ESTA FUNCION INICIALIZA EL keyword y retorna un len > 0 si es WORD
			if (len > 0)//si len tiene algo, INICIALIZARLO en 'value' porque es un WORD
			{
				//-----ASIGNA MEMORIA Y LA RELLENA CON EL STRING-------- 
				str = (char *)malloc(sizeof(char) * len + 1);
				if (!str)
					return ;//gestionar error, liberar y cerrar programa
				jc_strlcpy(str, line + i, len + 1);//rellenamos str con strlcpy(*src, *dst, dst_size)
				new_tok->value = str;//INICIALIZA el 'value' del NODO si es una WORD
				new_tok->keyword = WORD;
			}
			else
			{
				if (new_tok->keyword == DOUBLE_GREATER || new_tok->keyword == DOUBLE_SMALLER)
					len += 1;//por el doble operador
			}
				len++;
			jc_lstadd_back(&tokens, new_tok);
		}
		i += len;
	}
	lst_print(tokens);//ELIMINAR AL ENTREGAR
}
/* NOTAS
delimitadores (space, tab, "", '', < , >, <<, >>, |)
COMMAND: SIEMPRE va el primero de la linea y va el primero despues de un '|'
	Despues de comando  va siempre un argumento o una opcion.
OPERATOR (<, >, >>, <<): despues de un operador de estos, va siempre una WORD.
'|': NO puede NUNCA iniciar una linea. Si puede acabarla, no estoy seguro ...
echo pedro>fili = 4 tokens
=============================
PROXIMA TAREA: 
echo>>pedro  NO ve el doble operador, ve un simple >
echo>pedro   No ve para nada el operador
echo > pedro Si ve los 3
echo >> pedro Si ve los 3


-corregir este fallo (deberian ser 4 tokens y no 3): echo pedro>fili
-preparar el exit_status con los printers de los errores de bash
*/