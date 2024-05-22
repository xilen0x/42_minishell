# include "minishell.h"

int	builtin_unset(t_cmd *cmd, t_env **env)
{
	int		chk_exp;
	int		i;
	int		flag;

	flag = 0;
	//---------------UNSET SIN ARGUMENTOS
	if (size_arr2d(cmd->commands) == 1)
		return (0);
	//---------------UNSET + VARIABLE
	else
	{
		i = 1;
		while (cmd->commands[i] != NULL)
		{
			if (check_syntax(cmd->commands[i]))
			{
				ft_msgs(5, cmd);
				return (1);
			}
			chk_exp = check_export(cmd->commands[i]);
			if (chk_exp == 1 || chk_exp == 2)
				return (0);
			else
			{
				if (!(variable_exists_op3(*env, cmd->commands[i])))
					flag = 1;
				else
				{
					env_delone(env, &cmd->commands[i], &free);
					flag = 2;
				}
			}
			i++;
		}
		if (flag == 1)
			printf("Variable not found!\n");
		else if (flag == 2)
			printf("Variable successfully removed!\n");
	}
	return (0);
}
