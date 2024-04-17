#include "quote_rem.h"

/*Retorna el nombre de la variable de entorno a partir del puntero al inicio del nombre.
Si la variable existe tendra una sintaxis correcta
porque al ser creada con 'export' este ya lo verifica*/
/*En el contexto de la expansión de variables en Bash, los caracteres 
delimitadores son todos aquellos que no son guiones bajos, letras del alfabeto
 o números.*/
char *get_var_name(char *str)
{
	size_t 	i;
//	size_t	len;
	char	*var_name;

	i = 0;
//	len = 0;
	var_name = NULL;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var_name = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(var_name, str, i);
	return (var_name);
}