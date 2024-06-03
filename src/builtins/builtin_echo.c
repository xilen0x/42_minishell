/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:52:45 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 15:52:47 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* echo ~ option */
static int	echo_options(t_cmd *cmd, int i, int *print_newline)
{
	if (ft_strcmp(cmd->commands[1], "~") == 0)
	{
		printf("%s\n", getenv("HOME"));
		*print_newline = 0;
		return (0);
	}
	while (cmd->commands[i])
	{
		printf("%s", cmd->commands[i]);
		if (cmd->commands[i + 1] && cmd->commands[i][0] != '\0')
			printf(" ");
		i++;
	}
	return (0);
}

/* builtin echo */
int	builtin_echo(t_cmd *cmd)
{
	int	i;
	int	print_newline;

	i = 1;
	print_newline = 1;
	if (size_arr2d(cmd->commands) == 1)
	{
		printf("\n");
		// g_get_signal = 0;
		return (0);
	}
	if (ft_strcmp(cmd->commands[1], "-n") == 0)
	{
		print_newline = 0;
		i++;
	}
	echo_options(cmd, i, &print_newline);
	if (print_newline)
		printf("\n");
	// g_get_signal = 0;
	return (0);
}
