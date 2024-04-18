#include "quote_rem.h"

/*Retorna el nombre de la variable de entorno a partir del puntero al inicio del nombre.
Si la variable fue creada con 'export' ya se verifico su sintaxis, si entro como input
aqui se verifica.*/
char *get_var_name(char *str)
{
	size_t 	i;
//	size_t	len;
	char	*var_name;

	i = 0;
//	len = 0;
	var_name = NULL;
	if (str && ft_isdigit(str[0]))
	{
//		printf("Error de sintaxis en filename");
//		exit (EXIT_FAILURE);
		return (NULL);
	}
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var_name = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(var_name, str, i);
	return (var_name);
}