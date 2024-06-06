/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:59:21 by castorga          #+#    #+#             */
/*   Updated: 2024/06/06 17:59:23 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_child(int sig)
{
	if (sig == CTRL_C)
	{
		write(2, "\n", 1);
	}
}

void	signal_parent(int sig)
{
	if (sig == CTRL_C)
	{
		write(2, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		set_exit_status(1);
	}
}
