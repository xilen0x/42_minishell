/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:41:33 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 10:41:35 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Gets the length of a *str, frees it, and sets it to NULL*/
size_t	get_len_and_free(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	free(str);
	str = NULL;
	return (len);
}
