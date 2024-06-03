/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:46:36 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/03 10:11:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns the exit_status length of the last executed command*/
size_t	get_exit_status_len(void)
{
	size_t	len;
	char	*val;

	len = 0;
	val = get_exit_status_val();
	len = ft_strlen(val);
	free(val);
	return (len);
}
