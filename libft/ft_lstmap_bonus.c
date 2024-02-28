/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:03:46 by castorga          #+#    #+#             */
/*   Updated: 2023/06/12 09:03:49 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));

Parámetros 
lst: un puntero a un nodo.
f: la dirección de un puntero a una función usada en la iteración de cada 
elemento de la lista.
del: un puntero a función utilizado para eliminar el contenido de un nodo, 
si es necesario.

Valor devuelto 
La nueva lista.
NULL si falla la reserva de memoria.

Funciones autorizadas
malloc, free

Descripción 
Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo. 

Crea una lista resultante de la aplicación correcta y sucesiva de la 
función ’f’ sobre cada nodo. 

Función ’del’ se utiliza para eliminar el contenido de un nodo, si hace falta.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
//------------------------funcion extra de prueba la cual suma 2 a cada elemento
void	*ft_sum(void *content)
{
	int *data = (int *)content;

	*data += 2;

	return (content);
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

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);

	printf("Contenido de la lista antes de aplicar la funcion a los nodos: ");
	ft_print_list(node1);

	//llamada a la funcion ft_lstmap
	t_list *new_list = ft_lstmap(node1, ft_sum, free);
	if (new_list == NULL)
	{
		printf("Error: la función ft_lstmap falló\n");
		return (1);
	}

	printf("Contenido de la lista después de aplicar la función a los nodos: ");
	ft_print_list(new_list);

	// Liberar memoria
	ft_lstclear(&new_list, free);

	return (0);
}
*/

/*
castorga@cbr2s1 project01 % ./a.out
Contenido de la lista antes de aplicar la funcion a los nodos: 42 75 100
Contenido de la lista después de aplicar la función a los nodos: 44 77 102
*/