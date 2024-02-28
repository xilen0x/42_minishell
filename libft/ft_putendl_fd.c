/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:02:10 by castorga          #+#    #+#             */
/*   Updated: 2023/06/12 14:02:13 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Nombre de función
ft_putendl_fd

Prototipo 
void ft_putendl_fd(char *s, int fd);

Parámetros 
s: La string a enviar.
fd: El file descriptor sobre el que escribir.

Valor devuelto Nada

Funciones autorizadas
write

Descripción 
Envía la string ’s’ al file descriptor dado, seguido de un salto de línea.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	n;

	n = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &n, 1);
}

/*
int	main(void)
{
	ft_putendl_fd("holamundo42", 1);
}
*/
