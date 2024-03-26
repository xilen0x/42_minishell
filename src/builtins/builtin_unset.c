# include "minishell.h"

int	builtin_unset(t_built *cmd, t_env env, int ac)
{
	int	i;

	if (ac < 3)
		return (0);
	else
	{
		i = 0;
		while (env.env_cpy[i])
		{
			if (ca_strcmp(env.env_cpy[i], cmd->path) == 0)
			{
				free(env.env_cpy[i]);
				while (env.env_cpy[i + 1])// Mover el resto de las variables para llenar el espacio
				{
					env.env_cpy[i] = env.env_cpy[i + 1];
					i++;
				}
				env.env_cpy[i] = NULL; // Marcar el final del array
				return (0); // Éxito
			}
			i++;
		}
	}
	printf("Variable '%s' not found.\n", cmd->path);
	return (1);
}
