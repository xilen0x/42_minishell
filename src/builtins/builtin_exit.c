# include "minishell.h"

// int	ca_isnumber(const char *str)
// {
// 	while (*str)
// 	{
// 		if (!ft_isdigit(*str))
// 			return (0);
// 		str++;
// 	}
// 	return (1);
// }

static int	is_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

/*verifica si un str es un entero válido o no*/
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
		if ((res * sign > (LLONG_MAX - (str[i] - '0')) / 10) || (res * sign < (LLONG_MIN + (str[i] - '0')) / 10))
			return (-1);
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && is_space(str + i) == 0)
		return (-1);
	return (0);
}

int	builtin_exit(t_cmd *cmd)
{
	if (cmd->command_and_arg[1] && check_int(cmd->command_and_arg[1]) != 0)
	{
		printf("minishell: exit: numeric argument required\n");//exit aesae5 || exit - || exit ++- ...etc
		exit(255);
	}
	else if ((size_arr2d(cmd->command_and_arg)) == 1)
	{
		printf("exit\n");//exit solo
		printf("\033[40m");//black
		exit(0);
	}
	else if (cmd->command_and_arg[1])
	{
		if ((size_arr2d(cmd->command_and_arg)) > 2)
		{
			printf("minishell: exit: too many arguments\n");//exit 34 343
			// *exit_status = 1;
			return (1);
		}
		printf("exit\n");//exit 356
		exit(ft_atoi(cmd->command_and_arg[1]));
	}
	printf("exit\n");//otros casos
	//exit(*exit_status);
	exit(0);
	return (0);
}
