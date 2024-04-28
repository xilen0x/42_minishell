#include "minishell.h"

/*2ra fase: Rellena 'result' con los caracteres correctos que tendrá 
el nuevo token, una vez expandido y eliminadas comillas del token original 'str'*/
char	*new_tok_builder(char *str, t_env *envlist, char *result)
{
	size_t	i;
	size_t	j;
	t_qts	quotes;
	char	*tok_key;
	char	*tok_val;

	i = 0;
	j = 0;
	quotes.s_quote = 0;
	quotes.d_quote = 0;
	tok_val = NULL;
	while (str && str[i])
	{
		if (str[i] == '"' && quotes.d_quote == 0 && quotes.s_quote == 0)
			quotes.d_quote = 1;
		else if (str[i] == '"' && quotes.d_quote == 1)
			quotes.d_quote = 0;
		else if (str[i] == '\'' && quotes.s_quote == 0 && quotes.d_quote == 0)
			quotes.s_quote = 1;
		else if (str[i] == '\'' && quotes.s_quote == 1)
			quotes.s_quote = 0;
		else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1])//si es candidato a expandir.
		{
			i++;//salto el '$'
			tok_key = get_env_key(str + i);//puntero al inicio del nombre despues del '$'
			if (tok_key == NULL)//en caso de que despues de '$' haya un num o caracter especial
			{
				i++;
				continue;//OJO no se ejecutara nada de lo que hay a continuacion
			}
			tok_val = get_env_val(tok_key, envlist);//retorna el content de tok_key en env o NULL si no existe
			if (tok_val != NULL)
			{
				while (tok_val && *tok_val != '\0')
				{
					result[j] = (*tok_val);
					j++;
					tok_val++;
				}
			}
			i += ft_strlen(tok_key);//salto el len del nombre de la var en el recorrido del token
			free(tok_key);
			tok_key = NULL;
			tok_val = NULL;
			continue;//salto el ciclo para que no se incremente 'i' de nuevo
		}
		else
		{
//			len++; 
			result[j] = str[i];
			j++;
		}
		
		i++;
	}
	result[j] = '\0';
	return (result);
}