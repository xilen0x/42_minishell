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
/*------CREAMOS UN NODO PARA CADA TOKEN + INFO---------*/
t_token	*my_lstnew(void *content, int keyword, int position)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = content;
	token->keyword = keyword;
	token->position = position;
	token->next = NULL;
	return (token);
}

t_token    **tokenizer(char *line)
{
/*crear una lista de nodos **token
cada nodo contiene: 
    valor
    definicion o tipo 
    orden de aparicion en la CLI 
    
trimar spaces y tabs, delante y detras (hace falta ????)
*/
    char    *content = NULL;
    int     position = 0;
    int     keyword = 0;
    
if (*line)
{
    while (*line == ' ' || *line == '\t' || *line == '\t')
        line++;
    while (*line && *line != ???????????????????????????????)

    
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
