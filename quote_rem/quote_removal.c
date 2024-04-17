#include "quote_rem.h"

/*1ra fase: Calcula el len que tendra el token(str) una vez haya eliminado comillas 
y expandido las variables que procedan*/
int	tok_len(char *str)
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
		else if (str[i] == '$' && s_quote == 0 && str[i + 1])//si es candidato a expandir (en principio)
		{
			i++;//lo salto y me coloco en el siguiente caracter
//			var_name = get_var_name(str, i);//retorna el nombre de la variable despues del '$'
			var_name = get_var_name(str + i);//le paso de arg un puntero al inicio del nombre despues del '$'
			printf("El var_name encontrado es <%s>\n", var_name);//TEST TEMP
//			i += ft_strlen(var_name);
//			len += ft_strlen(env_var_find(var_name, env_t lst));//recorre la lista env buscando la var_name
			//y retorna el *content de la var o NUL, si no existe. Calculamos su len.

		}
		else
			len++; 
		i++;
	}
	return (len);
}

//void	quote_removal(char *str, char **environ)
char	*quote_removal(char *str, char **environ)
{
//	char	*dst;
	int	len;//TEST TEMP

	len = 0;//TEST TEMP
	printf("test:%s\n", environ[10]);//solo para que se use environ y no de problem al compilar
	len = tok_len(str);
	printf("len de quote_removal: %i\n", len);
//	dst = (char *)malloc(sizeof(char) * (len + 1));//creamos el malloc con el len
//	rellenamos el malloc//(usamos 2a fase de puertas) habra que expandir los $, si hay
	return (environ[3]);
}