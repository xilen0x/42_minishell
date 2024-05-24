#include "minishell.h"

/*Calcula el len que tendra el token(str) una vez haya eliminado comillas 
y expandido las variables que procedan*/
int	new_tok_len(char *str, t_env *envlist)
{
	size_t	i;
	size_t	len;
	t_qts	quotes;
	char	*env_key;
	char	*env_val;

	i = 0;
	len = 0;
	quotes.s_quote = 0;
	quotes.d_quote = 0;
	env_key = NULL;
	env_val = NULL;
	while (str[i])
//	while (str && str[i])
	{
		if (str[i] == '"' && quotes.d_quote == 0 && quotes.s_quote == 0)
			quotes.d_quote = 1;
		else if (str[i] == '"' && quotes.d_quote == 1)
			quotes.d_quote = 0;
		else if (str[i] == '\'' && quotes.s_quote == 0 && quotes.d_quote == 0)
			quotes.s_quote = 1;
		else if (str[i] == '\'' && quotes.s_quote == 1)
			quotes.s_quote = 0;
		else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1])//si es un '$' y despues hay algo
		{
			i++;//salto el '$'
//FILTRA NOMBRES SINTACTICAMENTE NO VALIDOS (en caso que despues del $  NO sea '?', alfabetico o '_')
			if (str[i] != '?' && !ft_isalpha(str[i]) && str[i] != '_')//ESTO NO SE EXPANDIRA, SINO QUE SE AÑADIRA TAL CUAL
			{
				len += 2;//cuento el '$' saltado hace dos lineas y el char actual no valido, porque los deberé añadir
//				while ((str[i] && str[i] != '$') || (str[i] && str[i] == '$' && str[i + 1] == '$'))//voy metiendo lo que encuentro en 'result' hasta encontrar otro '$' o '\0'
//				while ((str[i] && str[i] != '$' && (quotes.d_quote == 1 && str[i] != '"')) || (str[i] && str[i] == '$' && str[i + 1] == '$'))
//AQUI HE DE DIR: I SI LAS DOBLES COMILLAS ESTAN ABIERTAS (1) I NO ES UNA '"' ENTRA
//				{
//					i++;
//					len++;
//				}	
//				continue;
			}
			else if (str[i] == '?')//VERIFICA SI ES EL CASO ESPECIAL DEL '$?'
				len += get_exit_status_len();
			else//SI EL NOMBRE ES VALIDO SINTACTICAMENTE, BUSCARA SI CORRESPONDE CON UNA VARIABLE DE ENTORNO Y CONTARA SU LEN
			{
				env_key = get_env_key(str + i);//retorna un puntero mallocado al nombre despues del '$'
//				if (env_key != NULL)
//				{
				env_val = get_env_val(env_key, envlist);//busco su valor en el env y retorna un mallocado o un NULL si no lo hay
				if (env_val != NULL)
				{
					len += ft_strlen(env_val);//incremento el tamaño del nuevo token con el de la expansion
					free(env_val);
					env_val = NULL;
				}
				i += ft_strlen(env_key);//salto el len del nombre de la var en el recorrido del token
				free(env_key);
				env_key = NULL;
				continue;//salto el ciclo para que no se incremente 'i' de nuevo
			}
		}
		else
			len++; 
		i++;
	}
	return (len);
}