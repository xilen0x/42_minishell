/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:17:26 by joan              #+#    #+#             */
/*   Updated: 2024/06/02 16:30:03 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_iter(t_iter *iter)
{
	iter->i = 0;
	iter->len = 0;
}
