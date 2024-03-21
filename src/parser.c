#include "minishell.h"
/*
COMMAND: SIEMPRE va el primero de la linea y tambien despues de un '|'
Despues de comando va siempre una WORD (argumento o opcion).
OPERATOR (<, >, >>, <<, |): despues de un operador va siempre una WORD, NUNCA otro operador.
 La linia No puede acabar en un operador
'|': NO puede iniciar o acabar la linia
*/

void    parser(t_lst *tokens)//deberia recoger y devolver si hay un fallo de sintactico
{
//FUNCION CHECK DE TOKENS BASICOS 
    if (tokens->key == PIPE || ft_lstlast2(tokens)->key == PIPE)//si el 1ro o el ultimo son un | muestra error
        return (señal de error "bash: syntax error near unexpected token `|'");
    if (ft_lstlast2(tokens)->key == '<' || ft_lstlast2(tokens)->key == ' >' || ft_lstlast2(tokens)->key == '<<' || ft_lstlast2(tokens)->key == '>>' || ft_lstlast2(tokens)->key == '|')
    return (señal de error "bash: syntax error near unexpected token `newline'");
    


}