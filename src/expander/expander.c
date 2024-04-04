#include "minishell.h"

/*Función que obtiene y guarda los envp path*/
void	ft_get_paths(char **envp, t_env *data)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	data->paths = ft_split(&envp[i][5], ':');
}

