/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:45:07 by joan              #+#    #+#             */
/*   Updated: 2023/06/15 16:49:51 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Crea un nuevo nodo utilizando malloc(3). 
 *La variable miembro ’content’ se inicializa con el contenido del parámetro
 ’content’. La variable ’next’, con NULL.
 Cuando dejamos de usarlo hay que liberar la memeoria alojada por el  malloc.
 Retorna el nuevo nodo.*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node1;

	node1 = (t_list *)malloc(sizeof(t_list));
	if (!node1)
		return (NULL);
	node1->content = content;
	node1->next = NULL;
	return (node1);
}
