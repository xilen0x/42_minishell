/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:20:36 by castorga          #+#    #+#             */
/*   Updated: 2023/06/12 13:47:38 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
void ft_lstadd_front(t_list **lst, t_list *new);

Parámetros 
lst: puntero al primer nodo de una lista.
new: puntero al nodo que añadir al principio de la lista.

Valor devuelto 
Nada

Funciones autorizadas
Ninguna

Descripción 
Añade el nodo ’new’ al principio de la lista ’lst’.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != 0)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
static void	print_list(t_list *lst)
{
	int	*data;

	while (lst != 0)// mientras no se llegue al final de la lista
	{
		data = (int *)lst->content; //se obtiene el contenido del nodo actual
		printf("%d ", *data);// Imprime el contenido del nodo actual
		lst = lst->next;// Avanza al siguiente nodo de la lista
	}
	printf("\n");
}
*/
/*
int	main(void)
{
	// ------------------------ PRIMER NODO ------------------------
	int *data1 = (int *)malloc(sizeof(int));  // Asigna memoria x cont.
	*data1 = 42;  // Asigna el valor 42 al contenido del nodo
	t_list *node1 = (t_list *)malloc(sizeof(t_list));  //Asigna memoria x nodo
	node1->content = data1;  // Asigna el contenido al nodo
	node1->next = NULL;  // Establece el siguiente puntero del nodo como nulo

	// ------------------------ SEGUNDO NODO ------------------------
	int *data2 = (int *)malloc(sizeof(int));
	*data2 = 75;
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = data2;
	node2->next = NULL;

	// ------------ Agrega el segundo nodo al frente de la lista ------------
	ft_lstadd_front(&node1, node2);

	// ------------------------ PRINTS ------------------------
	printf("Contenido de la lista: ");
	print_list(node1);  // Imprime el contenido de la lista
	printf("Contenido del nodo1: %d\n", *(int *)(node1->content));
	printf("Contenido del nodo2: %d\n", *(int *)(node1->next->content));
	return (0);
}
*/
