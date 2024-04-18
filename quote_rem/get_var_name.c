#include "quote_rem.h"

/*Retorna el nombre de la variable de entorno a partir del puntero al inicio del nombre
y hasta encontrar una comilla simple o doble o un '\0'.
No tiene en cuenta si existe, ni si su sintaxis es valida.*/
char *get_var_name(char *str)
{
	size_t 	i;
	char	*var_name;

	i = 0;
	var_name = NULL;
//	if (*str == NULL)
//		return (NULL);
	while (str[i] && (str[i] != ' ' || str[i] != '"' || str[i] != '\''))
		i++;
	var_name = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(var_name, str, i);
	return (var_name);
}