#include "minishell.h"

/*Retorna un posible nombre de variable mallocado.
No tiene en cuenta si existe o no en el env.*/
char *get_env_key(char *str)
{
	size_t 	i;
	char	*var_name;

	i = 0;
	var_name = NULL;
//SI SON CARACTERES VALIDOS PARA UNA VARIABLE DE ENTORNO, CUENTALOS, RESERVA MEMORIA Y RELLENALA CON SU VALOR
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i > 0)
	{
	var_name = (char *)p_malloc(sizeof(char) * (i + 1));
	ft_strlcpy(var_name, str, i + 1);
	}
	return (var_name);
}
//SI HAY CARACTERES QUE NO SON ', ", $, \0, ME LOS LLEVO
//	while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$')
//		i++;
//	if (i > 0)
//	{
//		var_name = (char *)p_malloc(sizeof(char) * (i + 1));
//		ft_strlcpy(var_name, str, i + 1);
//	}
//	return (var_name);