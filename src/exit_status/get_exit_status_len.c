/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:46:36 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:47:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns the exit_status length of the last executed command*/
unsigned int	get_exit_status_len(void)
{
	unsigned int	len;
	char			*val;

	len = 0;
	val = get_exit_status_val();
	len = ft_strlen(val);
	free(val);
	return (len);
}
