/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:54:49 by castorga          #+#    #+#             */
/*   Updated: 2024/06/07 17:08:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_signal_handler(int signal, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handler;
	if (sigaction(signal, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (-1);
	}
	return (0);
}

int	set_parent_signals(void)
{
	if (set_signal_handler(CTRL_C, signal_parent) == -1)
		return (-1);
	if ((set_signal_handler(CTRL_SLASH, SIG_IGN) == -1) \
	|| (set_signal_handler(CTRL_Z, SIG_IGN) == -1))
		return (-1);
	return (1);
}

int	set_child_signals(void)
{
	if (set_signal_handler(CTRL_C, signal_child) == -1)
		return (-1);
	if ((set_signal_handler(CTRL_SLASH, SIG_IGN) == -1) \
	|| (set_signal_handler(CTRL_Z, SIG_IGN) == -1))
		return (-1);
	return (1);
}

int	set_signals(int mode)
{
	if (mode == PARENT)
		return (set_parent_signals());
	else if (mode == CHILD)
		return (set_child_signals());
	return (-1);
}
