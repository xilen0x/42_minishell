
#include "minishell.h"

/*====TODO LO QUE CONTIENE ESTE ARCHIVO AUN NO ESTA PROVADO=======*/

/*-----Returns the len of the first token found in 'line' */
/*INICIALIZA valor de 'keyword' del nodo y retorna un len > 0 si 'keyword' = WORD*/
int	tok_len(char *line, t_lst **new_tok)//args: puntero a inicio del token en 'line', un doble puntero al nodo
{
	int		len;
	char	c;

	len = 0;
	if (*line == '>' && *line == *(line + 1))//verifica si es doble
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
		while (*line && (*line != ' ' || *line != '\t' || *line != '|' \
		|| *line != '<' || *line != '>'))
		{
			if (*(line + len) == '\'' || *(line + len) == '"')//verifico si contiene comilla
			{
				c = *(line + len);//inicializo 'c' con el caracter comilla encontrado
				while (*(line + len) && *(line + len) != c)//mientras exista y no sea otra comilla
					len++;
				len--;//protector para que la siguiente linia no sobrepase el \0 o del final de la comilla ??
			}
			len++;
		}
	}
	return (len);
}

/*------------TOKENIZADOR------------*/
//EL 'value' DE TODOS LOS NODOS SERA NULL, EXCEPTO LOS DE keyword=WORD
t_lst	**tokenizer(char *line)//hace falta que sea const ??
{
	t_lst	**tokens;//lista de nodos con todos los tokens
	t_lst	*new_tok;//nodo con cada token
	char	*str;//el str que contendrá el token antes de meterlo en el nodo
	size_t	len;//la len del str del token
	int		i;//guardará el indice donde estamos en el recorrido por 'line'

	i = 0;
	len = 0;//hace falta inicializarlo???
	tokens = NULL;
	new_tok = NULL;

	//----OBTENDRA EL STRING DE CADA TOKEN HASTA LLEGAR AL FINAL DE 'line'--------
	while (line[i])//recorremos todo 'line'
	{
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))//salta espacios y tabs
        i++;
		if (line[i])
		{
			new_tok = lstnew_node(NULL, NULL_KEY);//creo un nodo y lo inicializo todo a 0 

			len = tok_len(line + i, &new_tok);//ESTA FUNCION INICIALIZA EL keyword y retorna un len > 0 si es WORD

			if (len > 0)//SOLO HABRA QUE MALLOCAR E INICIALIZAR 'value' si es un WORD
			{
				//-----ASIGNA MEMORIA Y LA RELLENA CON EL STRING-------- 
				str = (char *)malloc(sizeof(char) * len + 1);
				if (!str)
					return (EXIT_FAILURE);//gestionar error, liberar y cerrar programa
				ft_strlcpy(str, line + i, len + 1);//rellenamos str con strlcpy(*src, *dst, dst_size)
				new_tok->value = str;//INICIALIZA el 'value' del NODO si es una WORD
			}
			ft_lstadd_back(tokens, new_tok);
		}
		i += len;//actualizo el indice para que sepa que tramo de 'line' ya hemos recorrido
		i++;//No estoy seguro si habria que incrementar. Debugar y comprobar si es necesario
	}
	lst_print(tokens);
	return (tokens);
}

/* 
delimitadores (space, tab, "", '', < , >, <<, >>, |)
"hola>cat" = 1 token (se considera 1 solo argumento)
'hola>cat' = 1 token (se considera 1 solo argumento)
echo pedro>fili = 4 tokens
$ = si va solo, se tokeniza como una __WORD
$seguido_de_caracteres = se tokeniza como una __WORD
*/
