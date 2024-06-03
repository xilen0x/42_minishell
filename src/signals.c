/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:54:49 by castorga          #+#    #+#             */
/*   Updated: 2024/05/29 14:54:51 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_parent(int sig)
{
	if (sig == CTRL_C)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		// g_get_signal = 1;
	}
}

void	signal_child(int sig)
{
	if (sig == CTRL_C)
		write (2, "\n", 1);
}

int	set_signals(int mode)
{
	rl_catch_signals = 0;
	if (mode == PARENT)
	{
		signal(CTRL_C, signal_parent);
		signal(CTRL_SLASH, signal_parent);
	}
	else if (mode == CHILD)
	{
		signal(CTRL_C, signal_child);
	}
	return (1);
}
