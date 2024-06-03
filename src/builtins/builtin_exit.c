/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:22:00 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 16:22:03 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*checks if a str is a space or not.*/
static int	is_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

/*checks if a str is a valid integer or not.*/
int	check_int(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	i = is_space(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res * sign > (LLONG_MAX - (str[i] - '0')) / 10) || \
		(res * sign < (LLONG_MIN + (str[i] - '0')) / 10))
			return (-1);
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && is_space(str + i) == 0)
		return (-1);
	return (0);
}

/*builtin exit*/
int	builtin_exit(t_cmd *cmd)
{
	if (cmd->commands[1] && check_int(cmd->commands[1]) != 0)
	{
		printf("minishell: exit: numeric argument required\n");
		exit(255);
	}
	else if ((size_arr2d(cmd->commands)) == 1)
	{
		printf("exit\n");
		exit(0);
	}
	else if (cmd->commands[1])
	{
		if ((size_arr2d(cmd->commands)) > 2)
		{
			printf("minishell: exit: too many arguments\n");
			return (1);
		}
		printf("exit\n");//exit 356
		exit(ft_atoi(cmd->commands[1]));
	}
	printf("exit\n");
	exit(0);
	return (0);
}
