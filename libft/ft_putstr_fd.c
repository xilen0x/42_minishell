/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:04:25 by castorga          #+#    #+#             */
/*   Updated: 2023/06/12 14:04:28 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
void ft_putstr_fd(char *s, int fd);

Parámetros 
s: La string a enviar.
fd: El file descriptor sobre el que escribir.

Valor devuelto 
Nada

Funciones autorizadas
write

Descripción 
Envía la string ’s’ al file descriptor especificado.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
int	main(void)
{
	ft_putstr_fd("holamundo42\n", 1);
}
*/
