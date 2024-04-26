#include "minishell.h"

/*1ra fase: Calcula el len que tendra el token(str) una vez haya eliminado comillas 
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
	printf("token: %zu\n", ft_strlen(str));
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
//		else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1] == '?')
//		{
//
//
//
//
//		}
		else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1])//si es candidato a expandir.
		{
			i++;//salto el '$'
			env_key = get_env_key(str + i);//puntero al inicio del nombre despues del '$'
			if (env_key == NULL)//en caso de que despues de '$' haya un num o caracter especial
			{
				i++;
				continue;//OJO no se ejecutara nada de lo que hay a continuacion dentro del while
			}
			env_val = get_env_val(env_key, envlist);//retorna el content de env_key en env o NULL si no existe
			printf("1o_env_val <%s>\n", env_val);
			if (env_val != NULL)
			{
				printf("1o_len env_val = %zu\n", ft_strlen(env_val));
				len += ft_strlen(env_val);//incremento el tamanyo del nuevo token con el de la expansion
			}
			i += ft_strlen(env_key);//salto el len del nombre de la var en el recorrido del token
			free(env_key);
			env_key = NULL;
//			free(env_val);//si lo libero me cargo su contenido en el env
			env_val = NULL;
			continue;//salto el ciclo para que no se incremente 'i' de nuevo OJO: SE SALTARA TODO LO QUE TENGA DESPUES
		}
		else
			len++; 
		i++;
	}
	return (len);
}