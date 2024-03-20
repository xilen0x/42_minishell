
#include "minishell.h"

/*-----Returns the token's len pointed by 'line' */
/*INICIALIZA valor de 'keyword' del nodo y retorna un len > 0 si 'keyword' = WORD*/
int	tok_len(char *line, t_lst **new_tok)//args: puntero a inicio del token en 'line', un doble puntero al nodo
{
	int		len;
	char	c;

	len = 0;
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
			if (*(line + len))
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
			new_tok = lstnew_node(NULL, NULL_KEY);//creo un nodo y lo inicializo todo a 0 
			len = tok_len(line + i, &new_tok);//INICIALIZA EL keyword si es operador y retorna el len si es una WORD
			if (len > 0)//si contiene algo, es una WORD y la INICIALIZO su string en 'value'
			{
				//-----ASIGNA MEMORIA Y LA RELLENA CON EL STRING-------- 
				str = (char *)malloc(sizeof(char) * len + 1);
				if (!str)
					return ;//gestionar error, liberar y cerrar programa
				jc_strlcpy(str, line + i, len + 1);//rellenamos str con strlcpy(*src, *dst, dst_size)
				new_tok->value = str;//INICIALIZA el 'value' del NODO si es una WORD
				new_tok->keyword = WORD;
			}
			if (new_tok->keyword == DOUBLE_GREATER || new_tok->keyword == DOUBLE_SMALLER)
				len += 2;//por el doble operador
			if (new_tok->keyword == GREATER || new_tok->keyword == SMALLER || new_tok->keyword == PIPE)
				len += 1;;//por el operador simple
			jc_lstadd_back(&tokens, new_tok);
		}
		i += len;
	}
	lst_print(tokens);//ELIMINAR AL ENTREGAR
//	jc_lstclear(&tokens);
}
/* NOTAS PARA PARSER:
COMMAND: SIEMPRE va el primero de la linea y tambien despues de un '|'
Despues de comando va siempre una WORD (argumento o opcion).
OPERATOR (<, >, >>, <<, |): despues de un operador va siempre una WORD, NUNCA otro operador.
 La linia No puede acabar en un operador
'|': NO puede iniciar o acabar la linia
=============================
Las comillas (quote removal) y los expanders gestionarlos entre el parser y el executor
PROXIMAS TAREAS:
-preparar el exit_status con los printers de los errores de bash
*/