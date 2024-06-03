# include "minishell.h"

int	handle_no_argument(t_cmd *cmd)
{
	if (size_arr2d(cmd->commands) == 1)
	{
		return (go_home());
	}
	return (0);
}

int	handle_tilde(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], "~") == 0)
	{
		return (go_home());
	}
	return (0);
}

int	handle_dash(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], "-") == 0)
	{
		set_old_pwd();
		return (1);
	}
	return (0);
}

int	handle_dot(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], ".") == 0)
	{
		return (1);
	}
	return (0);
}

int	handle_invalid_path(t_cmd *cmd)
{
	if (ft_strcmp(cmd->commands[1], " ") == 0 || \
		ft_strcmp(cmd->commands[1], " / ") == 0)
	{
		ft_msgs(4, cmd);
		return (1);
	}
	return (0);
}
