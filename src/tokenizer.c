
#include "minishell.h"

/*====TODO LO QUE CONTIENE ESTE ARCHIVO AUN NO ESTA PROVADO=======*/

/*-----Returns the len of the first token found in 'line' */
/*int	tok_len(char *line, pasarli nodo per pillar el keyword)//El 'value' del keyword sera NULL excepte si es paraula
{
	int		len;
	char	c;

	len = 0;
	//CHECK_LEN_OPERATOR(intentar fer a fora i etiquetar un punter amb OPERATOR)
	if ((*line == '>' || *line == '<') && (*line == *(line + 1)))//verifica si es doble: <<, >>
		return(2);
	if (*line == '>' || *line == '<')//verifica si es simple <, >
		return (1);
	//CHECK_LEN_PIPE(intentar fer a fora i etiquetar un punter amb PIPE)
	if (*line == '|')
		return (1);

	//CHECK_LEN_WORD (intentar etiquetar un punter amb WORD)
	while (*line && (*line != ' ' || *line != '\t' || *line != '|' \
	|| *line != '<' || *line != '>'))
	{
		if (*(line + len) == '\'' || *(line + len) == '"')//verifico si contiene comilla
		{
			c = *(line + len);//inicializo 'c' con el caracter comilla encontrado
			while (*(line + len) && *(line + len) != c)//mientras exista y no sea otra comilla
				len++;//cuentalo
			len - 1;//protector para que la siguiente linia no lleve fuera del \0 o del final de la comilla ??
		}
		len++;
	}
	return (len);
}

//------------TOKENIZADOR------------//
t_lst    **tokenizer(const char *line)//hace falta el const ??
{
	t_lst	**tokens;//lista con todos los tokens
	t_lst	*new_tok;//nodo con cada token
	char	*str;//el str que contendrá el token antes de meterlo en el nodo
	int		len;//la len del str del token
	int		i;//guardará el indice donde estamos en el recorrido por 'line'

	i = 0;
	len = 0;//hace falta inicializarlo???
	tokens = NULL;
	new_tok = NULL;

	//crear el nodo vacio
	//new_tok->keyword = WORD;

	//----OBTENDRA EL STRING DE CADA TOKEN HASTA LLEGAR AL FINAL DE 'line'--------
	while (line[i])//recorremos todo 'line'
	{
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))//salta espacios y tabs
        i++;
							//aqui pasar el nodo para pillar el key
		len = tok_len(line + i, &new_tok->keyword);//calcula el len del token que encuentre en 'line'

		//-----ASIGNA MEMORIA Y LA RELLENA CON EL STRING-------- 
		str = (char *)malloc(sizeof(char) * len + 1);
		if (!str)
			return (EXIT_FAILURE);//gestionar error, liberar y cerrar programa

		ft_strlcpy(str, line + i, len + 1);//rellenamos str con strlcpy(*src, *dst, dst_size)

		i += len;//actualizo el indice para que sepa que tramo de 'line' ya hemos recorrido

		//---CREA/INICIALIZA UN NODO Y LO PONE AL FINAL DE LA LISTA

		//---------CONTINUAR AQUI

		new_tok = lstnew_tok(str,);//init/crea nodo
		//POTSER PUC POSAR LA CREACIO DINS DEL ADDBACK ??
		ft_lstadd_back(tokens, new_tok);
		//he de liberar str ????
	}
}

/* 
delimitadores (space, tab, "", '', < , >, <<, >>, |)
"hola>cat" = 1 token (se considera 1 solo argumento)
'hola>cat' = 1 token (se considera 1 solo argumento)
echo pedro>fili = 4 tokens
$ = si va solo, se tokeniza como una __WORD
$seguido_de_caracteres = se tokeniza como una __WORD
*/
