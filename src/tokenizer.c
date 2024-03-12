
#include "minishell.h"

/*====TODO LO QUE CONTIENE ESTE ARCHIVO AUN NO ESTA PROVADO=======*/

/*-----Returns the len of the first token found in 'line' */
int	tok_len(char *line)
{
	int		len;
	char	c;

	len = 0;
	if (*line == '>' || *line == '<' || *line == '|')//verifica si es: <, >, |
	{
		if (*line == *(line + 1) && *line != '|')//verifica si es: <<, >>
			return (2);
		return (1);
	}
	while (*line && (*line != ' ' || *line != '\t' || *line != '|' \
	|| *line != '<' || *line != '>'))//mientras exista y no sea: espacio, tab, |, <, >
	{
		if (*(line + len) == '\'' || *(line + len) == '"')//verifico si contiene comilla
		{
			c = *(line + len);//inicializo 'c' con el carcter comilla encontrado
			while (*(line + len) && *(line + len) != c)//mientras exista y no sea otra comilla
				len++;//cuentalo
		}
		len++;
	}
	return (len);
}

/*------------TOKENIZADOR------------*/
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
	
	//----OBTENDRA UN STRING DE CADA TOKEN HASTA LLEGAR AL FINAL DE 'line'--------
	while (line[i])//recorremos todo 'line'
	{
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))//salta espacios y tabs
        i++;

		len = tok_len(line + i);//calcula la len del token que encuentre en 'line' desde donde empieza

		//-----ASIGNA MEMORIA Y LA RELLENA CON EL STRING-------- 
		str = (char *)malloc(sizeof(char) * len + 1);
		if (!str)
			return (EXIT_FAILURE);//gestionar error, liberar y cerrar programa

		ft_strlcpy(str, line + i, len + 1);//rellenamos str con strlcpy(*src, *dst, dst_size)

		i += len;//actualizo el indice para que sepa que tramo de 'line' ya hemos recorrido

		//---CREA/INICIALIZA UN NODO Y LO PONE AL FINAL DE LA LISTA

---------CONTINUAR AQUI, a la funcio tok_len shauria de definir el keyword a traves dun punter

		new_tok = lstnew_tok(str, OJO pasarle el key *str);//init/crea nodo
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
