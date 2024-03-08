#include "minishell.h"

/*funcion temporal de inicializacion de estructura t_built*/
void	init(t_built *cmd, char *av[])
{
	cmd->echo = 0;
	cmd->cd = 0;
	cmd->pwd = 0;
	cmd->export = 0;
	cmd->unset = 0;
	cmd->env = 0;
	cmd->exit = 0;
	cmd->cmd1 = av[1];
	cmd->path = av[2];
}

int	main(int ac, char *av[], char *envp[])
{
    char	*line;
	t_env	env;
	t_built	cmds;
	/*if (ac != 1 || av[1])
	{
		printf("Arguments are not accepted!\n");
		return (0);
	}*/
	env.env_cpy = env_cpy(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			exit(1);
		}
		add_history(line);//agrega line al historial
		init(&cmds, av);
		builtings(&cmds, env, ac);
		free(line);
	}
	free(env.env_cpy);
	return (0);
}
