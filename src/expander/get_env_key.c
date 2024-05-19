#include "minishell.h"

/*Retorna un posible nombre de variable mallocado
No tiene en cuenta si existe, ni si su sintaxis es valida.*/
char *get_env_key(char *str)
{
	size_t 	i;
	char	*var_name;

	i = 0;
	var_name = NULL;
/*	
//SI NO SON CARACTERES VALIDOS PARA UNA VARIABLE DE ENTORNO
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (NULL);
	
//SI SON CARACTERES VALIDOS, CUENTALOS, RESERVA MEMORIA Y RELLENALA CON SU VALOR
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var_name = (char *)p_malloc(sizeof(char) * (i + 1));
	ft_strlcpy(var_name, str, i + 1);
	return (var_name);
*/
//	while (str[i])
	while (str[i] && str[i] != '\'' && str[i] != '"')
		i++;
	var_name = (char *)p_malloc(sizeof(char) * (i + 1));
	ft_strlcpy(var_name, str, i + 1);
	return (var_name);
}