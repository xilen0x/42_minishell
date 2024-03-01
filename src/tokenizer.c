/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:29:27 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/01 11:23:22 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

crear una lista de nodos **token
cada nodo contiene: 
    valor
    definicion o tipo 
    orden de aparicion en la CLI 
    
    

trimar spaces y tabs, delante y detras (hace falta ????)

while (que recorre *line)
 
split con delimitadores (space, tab, "", '', )
Los space y tabs, son delimitadores que se eliminan, no se usan  
"hola>cat" = 1 token (se considera 1 solo argumento)
'hola>cat' = 1 token (se considera 1 solo argumento)
echo pedro>fili = 4 tokens
$ = si va solo, se tokeniza como una __WORD
$seguido_de_caracteres = se tokeniza como una __WORD
|, <, >, <<, >>, 
        echo             hilo       = 2 tokens (los espacios se eliminan)
