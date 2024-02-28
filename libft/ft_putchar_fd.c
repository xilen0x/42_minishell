/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:01:29 by castorga          #+#    #+#             */
/*   Updated: 2023/06/14 15:47:07 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo
void ft_putchar_fd(char c, int fd);

Parámetros 
c: El carácter a enviar.
fd: El file descriptor sobre el que escribir.

Valor devuelto 
Nada

Funciones autorizadas
write

Descripción 
Envía el carácter ’c’ al file descriptor especificado.
*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main(void)
{
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
