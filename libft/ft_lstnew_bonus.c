/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:43:11 by castorga          #+#    #+#             */
/*   Updated: 2023/06/06 13:43:15 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipo 
t_list *ft_lstnew(void *content);

Parámetros 
content: el contenido con el que crear el nodo.

Valor devuelto 
El nuevo nodo

Funciones autorizadas
malloc

Descripción 
Crea un nuevo nodo utilizando malloc(3). La
variable miembro ’content’ se inicializa con el
contenido del parámetro ’content’. La variable
’next’, con NULL
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	else
		return (NULL);
	return (new_node);
}

/*
int	main(void)
{
	// Crear un nuevo nodo
	int *data = (int *)malloc(sizeof(int));
	*data = 42;

	t_list *node = ft_lstnew(data);
	// Imprimir el contenido del nodo
	if (node != NULL)
		printf("Contenido del nodo: %d\n", *(int *)(node->content));
	else
		printf("Error al crear el nodo.\n");
	// Liberar memoria
	free(data);
	free(node);
	return (0);
}
*/