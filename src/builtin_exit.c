/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:21:33 by castorga          #+#    #+#             */
/*   Updated: 2024/03/05 12:21:35 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtings(t_built	*cmd)
{
	int	i;

	i = 0;
	
	//printf("comando: %s\n", cmds.cmd1);
	if (cmd->exit)
	{
		printf("saliendo\n");
		exit(1);
	}
	else if (cmd->pwd)
	{
		printf("pwd\n");
		exit(1);
	}
	else if (cmd->env)
	{
		printf("env\n");
		exit(1);
	}
	else
	{
		printf("no soy el cmd exit\n");
	}
	return (0);
}
