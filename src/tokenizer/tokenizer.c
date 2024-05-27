#include "minishell.h"

//Tokeniza la 'line' sea cual sea, sin verificar errores sintacticos (separa por ' ', \t, <, >, >>, <<, |)
//'str' siempre sera NULL, excepto si es una WORD que contendra su string
//las comillas se tratan como WORD y si no estan cerradas se interpreta que llegan hasta fin de linea
void	tokenizer(t_tok **tok, char *line)
{
	t_tok	*new_tok;
	size_t	len;
	size_t	i;

	new_tok = NULL;
	i = 0;
	while (line && line[i])
	{
		len = 0;
    	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        	i++;
		if (line[i])
		{
			new_tok = tok_new_node(NULL, NULL_TYPE);//malloco node inicialitzat a NULL
			len = tok_len(line + i, &new_tok);//inicializa 'type' si es operador y retorna un 'len' > 0 si es una WORD
			init_word_str(len, new_tok, line, i);//si len > ), inicializo tok->str con la palabra mallocada y tok->type con el enum 'WORD' 
//			if (len > 0)//si len es > que 0, significa que hay una WORD. Reservo memoria y la meteo en tok->str. Meto 'WORD' en tok->type 
//			{
//				new_tok->str = (char *)p_malloc(sizeof(char) * (len + 1));//malloco *str dentro del nodo
//				ft_strlcpy(new_tok->str, line + i, len + 1);
//				new_tok->type = WORD;
//			}
			if (new_tok->type == DOUBLE_GREATER || new_tok->type == DOUBLE_SMALLER)
				len += 2;//por el doble operador
			if (new_tok->type == GREATER || new_tok->type == SMALLER || new_tok->type == PIPE)
				len += 1;//por el operador simple
			tok_add_back(tok, new_tok);
		}
		i += len;
	}
}
