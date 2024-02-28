/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:37:49 by castorga          #+#    #+#             */
/*   Updated: 2023/06/09 17:37:52 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
void ft_lstiter(t_list *lst, void (*f)(void *));

Parámetros 
lst: un puntero al primer nodo.
f: un puntero a la función que utilizará cada nodo.

Valor devuelto
Nada

Funciones autorizadas
Ninguna

Descripción 
Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada nodo.
*/
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != 0)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
//------------------------funcion extra de prueba la cual suma 2-------------
void	ft_sum(void *content)
{
    int *data = (int *)content;
    *data += 2;
}

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
*/

/*
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

	//node1->next = NULL;
	//node2->next = NULL;
	//node3->next = NULL;

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);

	printf("Contenido de la lista antes de aplicar la funcion a los nodos: ");
	ft_print_list(node1);
	
	//llamada a la funcion
	ft_lstiter(node1, ft_sum);

	printf("Contenido de la lista despues de aplicar la funcion a los nodos: ");
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
castorga@cbr5s5 project01% ./a.out
Contenido de la lista antes de aplicar la funcion a los nodos: 42 75 100
Contenido de la lista despues de aplicar la funcion a los nodos: 44 77 102
*/