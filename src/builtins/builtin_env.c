/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:15:26 by castorga          #+#    #+#             */
/*   Updated: 2024/05/30 12:29:48 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	no_path_env(t_cmd *cmd, t_exe exe, t_env *env)
{
	int		flag;

	(void)exe;
	flag = 0;
	while (env)
	{
		if (variable_exists_op3(env, "PATH"))
			flag = 1;
		env = env->next;
	}
	if (flag == 0)
	{
		// executor(cmd, &exe, &env);//aki voy
		ft_msgs(4, cmd);
		return (1);
	}
	return (0);
}

void	print_env(t_env *env)
{
	while (env)
	{
		if (!(ft_strchr(env->val, 32)) || (ft_strcmp(env->key, "PATH") == 0))
			printf("%s=%s\n", env->key, env->val);
		env = env->next;
	}
}

/*builtin que imprime el environment*/
int	builtin_env(t_cmd *cmd, t_exe exe, t_env *env)
{
	if (size_arr2d(cmd->commands) > 1)
	{
		if ((ft_strcmp(cmd->commands[1], "test") == 0) || \
		(ft_strcmp(cmd->commands[1], "true") == 0) || \
		(ft_strcmp(cmd->commands[1], "false") == 0))
			return (1);
		else if (ft_strcmp(cmd->commands[1], "echo") == 0)
		{
			printf("\n");
			return (0);
		}
		else
			ft_msgs(4, cmd);
		return (1);
	}
	else
	{
		if (no_path_env(cmd, exe, env))
			return (1);
		print_env(env);
	}
	g_get_signal = 0;
	return (0);
}
