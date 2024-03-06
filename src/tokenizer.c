/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:29:27 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/06 19:12:17 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*====TODO LO QUE CONTIENE ESTE ARCHIVO AUN NO ESTA PROVADO=======*/
/*------RETORNA UN NUEVO NODO CREADO CON LOS ARGUMENTOS---------*/t_lst	*my_lstnew(void *value, int keyword)
{
	t_lst	*token;

	token = (t_lst *)malloc(sizeof(t_lst));
	if (!token)
		return (NULL);
	token->value = *value;
	token->keyword = keyword;
    token->next = NULL;
	return (token);
}

/*----RETURNS A POINTER TO THE LAST NODE OF A LIST----*/
t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*----ADDS A NODE TO THE END OF A LIST. NOTHING IS RETURNED---*/
void	ft_lstadd_back(t_lst **lst,t_lst *new)
{
	t_lst	*aux;

	if (*lst)
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}

/*------------TOKENIZADOR------------*/
t_lst    **tokenizer(const char *line)//hace falta el const ??
{
	t_lst	*tokens;//La lista con todos los tokens
	t_lst	*tok;//El nodo de cada token
	
	tokens = NULL;
	tok = NULL;
	
//	buscamos el len del token
//	buscamos el str del token y el keyword
//	creamos un malloc tipo char* y se lo asignamos
	
    while (*line && (*line == ' ' || *line == '\t'))
        line++;
    while  (*line && *line != ???????????????????????????????)
    {
        
    }
	if (*line == '\0')
	
	}
    
} 

 
split con delimitadores (space, tab, "", '', < , >, <<, >>, |)
' ' , \t, son delimitadores que se eliminan, no se usan  
"hola>cat" = 1 token (se considera 1 solo argumento)
'hola>cat' = 1 token (se considera 1 solo argumento)
echo pedro>fili = 4 tokens
$ = si va solo, se tokeniza como una __WORD
$seguido_de_caracteres = se tokeniza como una __WORD
|, <, >, <<, >>, 
        echo             hilo       = 2 tokens (los espacios se eliminan)
