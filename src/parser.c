#include "minishell.h"

void    parser(t_comm comm, t_lst *tokens)//deberia recoger y devolver si hay un fallo sintactico
{
    t_comm  *node;

    //CHECK DE REGLAS SINTACTICAS BASICAS
    if (!tokens && *tokens->key == NULL_KEY)//protector, hace falta?
         return (señal de error "minishell: syntax error near unexpected token `newline'");//ARREGLAR

    if (tokens->key == PIPE || jc_lstlast(tokens)->key == PIPE)//si el 1ro o el ultimo es un '|'
        return (señal de error "minishell: syntax error near unexpected token `|'");//ARREGLAR

    if (jc_lstlast(tokens)->key == GREATER || jc_lstlast(tokens)->key == SMALLER \
    || jc_lstlast(tokens)->key == D_GREATER || jc_lstlast(tokens)->key == D_SMALLER \
    || jc_lstlast(tokens)->key == PIPE)//si linea acaba en un operador
        return (señal de error "minishell: syntax error near unexpected token `newline'");//ARREGLAR

//    si despues de un operador hay algo que no sea una WORD, retorna Error
    if (tokens->key == GREATER || tokens->key == SMALLER || tokens->key == D_GREATER || tokens->key == D_SMALLER || tokens->key == PIPE)
        if(tokens->next->key != WORD)
            return (señal de error "minishell: syntax error near unexpected token `newline'");//ARREGLAR


    //recorrer lista 'tokens' para crear nodo 'comm' con cada pipeline.
    while (tokens && tokens->key != PIPE && tokens->key != NULL_KEY)
//        t_lst   aux;//creo que no lo necesito para recorrer la lista
    {
        crear node, hacer una nueva funcion con los valores (la struct) que quiero que contenga
        inicializarlo a 0
        rellenarlo con la info de los tokens
    }

}
/* NOTAS PARA PARSER:
Si el operador es > o >>, el siguiente sera un fd_out, si es <, sera un fd_in. Esto << no tengo claro
*/