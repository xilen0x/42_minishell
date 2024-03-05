/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:29:27 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/01 16:27:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*------CREAMOS UN NODO PARA CADA TOKEN---------*/
t_list	*my_lstnew(void *content, int keyword)
{
	t_list	*token;

	token = (t_list *)malloc(sizeof(t_list));
	if (!token)
		return (NULL);
	token->value = *value;
	token->keyword = keyword;
    token->next = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst)
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}

t_list    **tokenizer(char *line)
{
/*crear una lista de nodos **token
cada nodo contiene: 
    valor
    definicion o tipo 
    
trimar spaces y tabs, delante y detras (hace falta ????)
*/
    char    *content = NULL;
    int     position = 0;
    int     keyword = 0;
}

if (*line)
{
    while (*line == ' ' || *line == '\t' || *line == '\n')
        line++;
    while (*line && *line != ???????????????????????????????)
    {
        
    }

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
