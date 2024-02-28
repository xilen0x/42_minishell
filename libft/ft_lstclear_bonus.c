/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:25:43 by castorga          #+#    #+#             */
/*   Updated: 2023/06/09 11:25:45 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
void ft_lstclear(t_list **lst, void (*del)(void*));

Parámetros 
lst: la dirección de un puntero a un nodo.
del: un puntero a función utilizado para eliminar el contenido de un nodo.

Valor devuelto 
Nada

Funciones autorizadas
free

Descripción 
Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo, 
utilizando la función ’del’ y free(3).
Al final, el puntero a la lista debe ser NULL
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
/*
//------------------------funcion que imprime la lista------------------------
static void	ft_print_list(t_list *lst)
{
	int	*data;

	while (lst != NULL)
	{
		data = (int *)lst->content; //se obtiene el contenido del nodo actual
		printf("%d ", *data);// Imprime el contenido del nodo actual
		lst = lst->next;// Avanza al siguiente nodo de la lista
	}
	printf("\n");
}

//------------------------funcion main------------------------
int	main(void)
{
	// Crear una lista con algunos nodos
	t_list *node1 = ft_lstnew(malloc(sizeof(int)));
	t_list *node2 = ft_lstnew(malloc(sizeof(int)));
	t_list *node3 = ft_lstnew(malloc(sizeof(int)));

	// Asignar datos a los nodos
	*(int *)(node1->content) = 42;
	*(int *)(node2->content) = 75;
	*(int *)(node3->content) = 100;

	// Enlazar los nodos
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

	printf("Contenido de la lista antes de eliminar los nodos: ");
	ft_print_list(node1);

	ft_lstclear(&node1, &free); //elim nodox.

	printf("Contenido de la lista después de eliminar los nodos: ");
	ft_print_list(node1);

	free(node1);

	return (0);
}
*/

/*
castorga@cbr5s5 project01 %% ./a.out
Contenido de la lista antes de eliminacion de nodo: 42 75 100
Contenido de la lista despues de eliminacion de nodo:
*/