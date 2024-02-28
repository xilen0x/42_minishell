/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:23:06 by castorga          #+#    #+#             */
/*   Updated: 2023/06/09 10:23:11 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
void ft_lstdelone(t_list *lst, void (*del)(void*));

Parámetros 
lst: el nodo a liberar.(A pointer to the node that needs to be deleted.)
del: un puntero a la función utilizada para liberar el contenido del nodo.

Valor devuelto 
Nada

Funciones autorizadas
free

Descripción 
Toma como parámetro un nodo ’lst’ y libera la memoria del contenido utilizando 
la función ’del’ dada como parámetro, además de liberar el nodo. La memoria de 
’next’ no debe liberarse.

Elimina, libera y aplica la función 'del' al contenido de un nodo dado
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
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
	int *data1 = (int *)malloc(sizeof(int));
	int *data2 = (int *)malloc(sizeof(int));
	int *data3 = (int *)malloc(sizeof(int));
	*data1 = 42;
	*data2 = 75;
	*data3 = 100;

	t_list *node1 = ft_lstnew(data1);
	t_list *node2 = ft_lstnew(data2);
	t_list *node3 = ft_lstnew(data3);

	node1->next = NULL;
	node2->next = NULL;
	node3->next = NULL;

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);

	printf("Contenido de la lista antes de eliminacion de nodo: ");
	ft_print_list(node1);
	
	// eliminacion contenido nodo
	ft_lstdelone(node2, &free);

	printf("Contenido de la lista despues de eliminacion de nodo: ");
	ft_print_list(node1);

	// Liberar memoria
	free(data1);
	//free(data2);
	free(data3);
	free(node1);
	//free(node2);
	free(node3);

	return (0);
}
*/

/*
castorga@cbr5s5 project01 %% ./a.out
Contenido de la lista antes de eliminacion de nodo: 42 75 100
Contenido de la lista despues de eliminacion de nodo: 42 0 100
*/