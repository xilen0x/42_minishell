#include "minishell.h"

/*funcion temporal de inicializacion*/
void	init(t_built *cmd, char *av[])
{
	cmd->echo = 0;
	cmd->cd = 0;
	cmd->pwd = 0;
	cmd->export = 0;
	cmd->unset = 0;
	cmd->env = 0;
	cmd->exit = 0;
	cmd->cmd1 = av[1];//cambiar luego
}

int	main(int ac, char *av[], char *envp[])
{
    char	*line;
	(void)ac;
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
		//set_signals(INTER);
		line = readline("minishell$ ");
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			exit(1);
		}
		add_history(line);//agrega line al historial
		init(&cmds, av);
		builtings(&cmds, env);
		free(line);
	}
	free(env.env_cpy);
	return (0);
}
