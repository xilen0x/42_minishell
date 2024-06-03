/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status_val.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:47:26 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/28 17:48:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns a mallocated char* with the last executed command exit_status value*/
char	*get_exit_status_val(void)
{
	char	*result;

	// result = ft_itoa(g_get_signal);//cambio temporal para eliminar errores en linux de variable global
	result = ft_itoa(0);
	if (!result)
		exit (EXIT_FAILURE);
	return (result);
}
