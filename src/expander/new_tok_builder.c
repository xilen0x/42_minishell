#include "minishell.h"

/*2ra fase: Rellena 'result' con los caracteres correctos que tendrá 
el nuevo token, una vez expandido y eliminadas comillas del token original 'str'*/
char	*new_tok_builder(char *str, t_env *envlist, char *result, unsigned int *exit_status)
{
	size_t	i;
	size_t	j;
	t_qts	quotes;
	char	*env_key;
	char	*env_val;

	i = 0;
	j = 0;
	quotes.s_quote = 0;
	quotes.d_quote = 0;
	env_key = NULL;
	env_val = NULL;
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
			if (str[i] == '?')
			{
				env_val = get_exit_status_val(exit_status);//retorna un char* mallocado
				while (env_val && *env_val != '\0')
				{
					result[j] = (*env_val);
					j++;
					env_val++;
				}
				free (env_val);
				env_val = NULL;
			}
			else//verifica si es un nombre de variable valido y si es de entorno o no
			{
				env_key = get_env_key(str + i);//puntero al inicio del nombre despues del '$'
//				if (env_key != NULL)
				env_val = get_env_val(env_key, envlist);//retorna el content mallocado de tok_key en env o NULL si no existe
//				if (env_val != NULL)
//				{
				while (env_val && *env_val != '\0')
				{
					result[j] = (*env_val);
					j++;
					env_val++;
				}
//				}
				i += ft_strlen(env_key);//salto el len del nombre de la var en el recorrido del token
				free(env_key);
				env_key = NULL;
				free(env_val);
				env_val = NULL;
				continue;//salto el ciclo para que no se incremente 'i' de nuevo
			}
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
	free(str);//libera el antiguo token
	return (result);//esta mallocado
}