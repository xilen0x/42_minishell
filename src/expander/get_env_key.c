#include "minishell.h"

/*Retorna el nombre de la variable de entorno a partir del puntero al inicio del nombre
y hasta encontrar una comilla simple o doble o un '\0'.
No tiene en cuenta si existe, ni si su sintaxis es valida.*/
char *get_env_key(char *str)
{
	size_t 	i;
	char	*var_name;

	i = 0;
	var_name = NULL;
	if (str[i] == '?')//SI ES UN '?'
	{
		var_name = (char *)malloc(sizeof(char) * 2);
		if (!var_name)
		{
			free(var_name);//NO ESTOY SEGURO 
			return (NULL);
		}
		ft_strlcpy(var_name, str, i + 1);
		return (var_name);
	}
/*SI NO SON CARACTERES VALIDOS PARA UNA VARIABLE DE ENTORNO*/
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (NULL);
/*SI SON CARACTERES VALIDOS, CUENTALOS, RESERVA MEMORIA Y RELLENALA CON SU VALOR*/
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var_name = (char *)malloc(sizeof(char) * (i + 1));
	if (!var_name)
	{
		free(var_name);//NO ESTOY SEGURO 
		return (NULL);
	}
	ft_strlcpy(var_name, str, i + 1);
	return (var_name);
}