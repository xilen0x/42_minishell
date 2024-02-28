/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:47 by castorga          #+#    #+#             */
/*   Updated: 2023/06/08 16:12:50 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
t_list *ft_lstlast(t_list *lst);

Parámetros 
lst: el principio de la lista.

Valor devuelto 
Último nodo de la lista.

Funciones autorizadas
Ninguna

Descripción 
Devuelve el último nodo de la lista.
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void)
{
// declaro e inicializo punteros
	int *data1 = (int *)malloc(sizeof(int));
	int *data2 = (int *)malloc(sizeof(int));
	int *data3 = (int *)malloc(sizeof(int));
	int *data4 = (int *)malloc(sizeof(int));
	*data1 = 10;
	*data2 = 11;
	*data3 = 12;
	*data4 = 13;

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

// obtengo el ultimo nodo de la lista
	t_list *lastNode = ft_lstlast(node1);

// imprimo contenido de ultimo nodo de la lista
	printf("Contenido del ultimo nodo: %d\n", *(int *)(lastNode->content));

// libero memoria
	free(data1);
	free(data2);
	free(data3);
	free(data4);
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return (0);
}*/