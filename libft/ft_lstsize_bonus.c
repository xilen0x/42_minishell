/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:50:45 by castorga          #+#    #+#             */
/*   Updated: 2023/06/08 13:50:47 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo
int ft_lstsize(t_list *lst);

Parámetros 
lst: el principio de la lista.

Valor devuelto 
La longitud de la lista.

Funciones autorizadas
Ninguna

Descripción 
Cuenta el número de nodos de una lista.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
/*
int	main(void)
{
// declaro e inicializo punteros
	int *data1 = (int *)10;
	int *data2 = (int *)11;
	int *data3 = (int *)12;
	int *data4 = (int *)13;

// Creo nuevos nodos
	t_list *node1 = ft_lstnew(data1);
	t_list *node2 = ft_lstnew(data2);
	t_list *node3 = ft_lstnew(data3);
	t_list *node4 = ft_lstnew(data4);

// asigno a content de cada nodo, la data
	node1->content = data1;
	node2->content = data2;
	node3->content = data3;
	node4->content = data4;

// asigno a next de cada nodo, su nuevo puntero
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

// imprimo longitud de la lista
	printf("%d\n", ft_lstsize(node1));

// libero memoria
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return (0);
}
*/