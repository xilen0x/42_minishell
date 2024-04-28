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
	if (str[i] == '?')
	{
		var_name = (char *)malloc(sizeof(char) * 2);
		ft_strlcpy(var_name, str, i + 1);
		return (var_name);
	}
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (NULL);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var_name = (char *)malloc(sizeof(char) * (i + 1));
	if (!var_name)
	{
		free(var_name);//AQUI QUIZAS HABRIA QUE LIBERAR TODO Y SALIR?
		return (NULL);
	}
	ft_strlcpy(var_name, str, i + 1);
	return (var_name);
}