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

int	builtings(t_data	*cmd)
{
	int	i;

	i = 0;
	cmd->cmd1 = av[1];
	if (ft_strcmp(cmd->cmd1,"exit") == 0)
	{
		printf("saliendo\n");
		exit(1);
	}
	else
	{
		printf("no soy el cmd exit\n");
	}
	return (0);
}
