/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:31:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/01 14:20:08 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_env(char **env)
// {
// 	int	i = 0;

// 	while (env[i])
// 	{
// 		printf("%s\n", env[i]);
// 		i++;
// 	}
// }

int	main(int ac, char *av[], char *envp[])
{
    char	*line;
	(void)ac;
	t_env	env;
	t_data	cmds;
	if (ac != 1 || av[1])
	{
		printf("Arguments are not accepted!\n");
		return (0);
	}
	env.env_cpy = env_cpy(envp);
	//printf("comando: %s\n", cmds.cmd1);
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
		builtings(&cmds);
		free(line);
	}
	free(env.env_cpy);
	return (0);
}
