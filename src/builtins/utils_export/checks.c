/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:46:09 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 16:46:11 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*check if export argument comes with = or += */
unsigned int	check_export(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && (ft_isalpha(arg[i]) || \
			arg[i] == '_' || ft_isdigit(arg[i])))
		i++;
	if (arg[i] == '+')
	{
		if (ft_strncmp(&arg[i], "+=", 2) == 0)
			return (2);
	}
	else if (arg[i] == '=')
		return (1);
	else
		return (3);
	return (0);
}

/*check if the syntax of the export command is correct */
int	check_syntax(char *cmd)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(cmd[i]) || cmd[i] == '_'))
		return (1);
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_' \
		&& cmd[i] != '=' && cmd[i] != '+')
			return (1);
		if (cmd[i] == '=' && i > 0)
			return (0);
		i++;
	}
	return (0);
}
