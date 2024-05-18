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
		else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1])//si es un '$' y despues hay algo
		{
			i++;//salto el '$'
			if (str[i] && str[i] == '?')
				len += get_exit_status_len();
			else//verifica si despues de $ hay un nombre de variable valido y si es de entorno o no
			{
				env_key = get_env_key(str + i);//si podria ser valido retorna un puntero mallocado al nombre despues del '$' o un NULL no mallocado
				if (env_key != NULL)//en caso de que el nombre NO sea NULL (o sea, un num o un caracter especial)
				{
					env_val = get_env_val(env_key, envlist);//busco su valor en el env y retorna un mallocado o un NULL
					if (env_val != NULL)
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