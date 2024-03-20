#include "minishell.h"
/*
COMMAND: SIEMPRE va el primero de la linea y tambien despues de un '|'
Despues de comando va siempre una WORD (argumento o opcion).
OPERATOR (<, >, >>, <<, |): despues de un operador va siempre una WORD, NUNCA otro operador.
 La linia No puede acabar en un operador
'|': NO puede iniciar o acabar la linia
*/

void    parser(t_lst *tokens)
{


}