#include "quote_rem.h"

/*1ra fase: Calcula el len que tendra el token(str) una vez haya eliminado comillas 
y expandido las variables que procedan*/
int	tok_len(char *str, t_env *envlist)
{
	size_t	i;
	int		len;
	int		s_quote;
	int		d_quote;
	char	*var_name;

	i = 0;
	len = 0;
	s_quote = 0;
	d_quote = 0;
	var_name = NULL;
	while (str && str[i] != '\0')
	{
		if (str[i] == '"' && d_quote == 0 && s_quote == 0)
			d_quote = 1;
		else if (str[i] == '"' && d_quote == 1)
			d_quote = 0;
		else if (str[i] == '\'' && s_quote == 0 && d_quote == 0)
			s_quote = 1;
		else if (str[i] == '\'' && s_quote == 1)
			s_quote = 0;
//		else if (str[i] == '$' && s_quote == 1 && str[i + 1])//si no se expandira, necesito su tamanyo literal		{		}

		else if (str[i] == '$' && s_quote == 0 && str[i + 1])//si es candidato a expandir.
		{
			i++;//me coloco en el siguiente caracter al '$'
//			len++;//cuento el caracter '$'
			var_name = get_var_name(str + i);//arg es un puntero al inicio del nombre despues del '$'
			printf("var_name: <%s>\n", var_name);//TEST TEMP
//			busco el content de var_name y si existe la sumo a len del token (ademas incremento i en la len de var_name)
//			(si cont_env_find fuese NULL, porque no existe, no sumo nada a len (pero si que incremento i con el len de var_name)
//			len += ft_strlen(cont_env_finder(var_name, environ))//retorna el content

			i += ft_strlen(var_name);

			
//			len += ft_strlen(env_var_find(var_name, env_t lst));//recorre la lista env buscando la var_name
			//y retorna el *content de la var o NUL, si no existe. Calculamos su len.
//		si cont_env_find retorna NULL porque no existe su var_name en env, no sumo nada a len y salto todo el var_name)

		}

		else
			len++; 
		i++;
	}
	return (len);
}

//void	quote_removal(char *str, char **environ)
char	*quote_removal(char *str, t_env *envlist)
{
	char	*result;
	int	len;//TEST TEMP

	len = 0;//TEST TEMP
	printf("entra a quote_removal\n");
	len = tok_len(str, envlist);
	printf("len de quote_removal: %i\n", len);
//	result = (char *)malloc(sizeof(char) * (len + 1));//creamos el malloc con el len
//	rellenamos el malloc//(usamos 2a fase de puertas) habra que expandir los $, si hay
	return (result);
}