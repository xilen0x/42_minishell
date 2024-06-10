/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:49:56 by castorga          #+#    #+#             */
/*   Updated: 2024/06/07 17:26:28 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns 1 if 'c' ('\0' included) is located in 's', otherwise returns 0*/
int	ca_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char) c;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*Frees and sets to NULL a char *str passed as argument by reference*/
void	str_free_and_null(char **str)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
}
