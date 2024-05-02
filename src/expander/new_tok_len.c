#include "minishell.h"

/*Calcula el len que tendra el token(str) una vez haya eliminado comillas 
y expandido las variables que procedan*/
int	new_tok_len(char *str, t_env *envlist)//unsigned int/int exit_status
{
	size_t	i;
	size_t	len;
	t_qts	quotes;
	char	*env_key;
	char	*env_val;
//	char	*exit_status_val;

	i = 0;
	len = 0;
	quotes.s_quote = 0;
	quotes.d_quote = 0;
	env_key = NULL;
	env_val = NULL;
//	exit_status_val = NULL;
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
//			if (str[i] == '?')
//			{
//				exit_status_val = itoa(exit_status);//crear esta variable y pasarla a cada funcion que la necesite
//				len += ft_strlen(exit_status_val);
//				free(exit_status_val);
//			}
//			else
//			{
				env_key = get_env_key(str + i);//puntero al inicio del nombre despues del '$'
				if (env_key != NULL)//en caso de que despues de '$' haya un num o caracter especial
				{
					// i++;
					// continue;//OJO no se ejecutara nada de lo que hay a continuacion dentro del while
					env_val = get_env_val(env_key, envlist);
					if (env_val != NULL)
					{
						len += ft_strlen(env_val);//incremento el tamaño del nuevo token con el de la expansion
					}
					i += ft_strlen(env_key);//salto el len del nombre de la var en el recorrido del token
					free(env_key);
					env_key = NULL;
					env_val = NULL;
					continue;//salto el ciclo para que no se incremente 'i' de nuevo
				}
//			}
		}
		else
			len++; 
		i++;
	}
	return (len);
}