#include "minishell.h"

void    parser(t_cmd *cmd, t_lst *tokens)
{
    t_cmd           *node;
    t_lst           *tmp;//puntero al ultimo token de la lista
    unsigned int    i;

    tmp = lst_last(tokens);
    //CHECK PARA DESCARTAR ERRORES GRAMATICALES INICIALES
    if (!tokens && tokens->key == NULL_KEY)//protector, hace falta?
         return (perror "minishell: syntax error near unexpected token `newline'");//ARREGLAR

    if (tokens->key == PIPE || tmp->key == PIPE)//si 1ro o ultimo es un '|'
        return (perror "minishell: syntax error near unexpected token `|'");//ARREGLAR

    if (tmp->key == GREATER || tmp->key == SMALLER \
    || tmp->key == D_GREATER || tmp->key == D_SMALLER)//si linea acaba en operador
        return (perror "minishell: syntax error near unexpected token `newline'");//ARREGLAR

    if ((tokens->key == GREATER || tokens->key == SMALLER \
    || tokens->key == D_GREATER || tokens->key == D_SMALLER \
    || tokens->key == PIPE) && tokens->next->key != WORD)//si despues de operador NO hay una WORD
            return (perror "minishell: syntax error near unexpected token `newline'");//ARREGLAR

    tmp = tokens;//ahora lo inicializo al inicio de tokens
//recorre toda la lista 'tmp' para crear un nodo 'comm' con cada pipeline.
    while (tmp && tmp->key != NULL_KEY)
    {
        node = new_cmd_node(); 
        i = 0;

//recorre hasta encontrar un pipeline, que sera un nodo, y va inicializando todas sus variables
        while (tmp && tmp->key != NULL_KEY && tmp->key != PIPE)
        {
            if (tmp->key == WORD)
            {
>>>>>>>>>>>>>>> contador de elementos para la matriz
                aqui malloc de la matriz
                node->cmd_arg[i] = ft_strdup(tmp->val);//
                i++;
                tmp = tmp->next;

            }
            else if ()
            {

            }
            else if ()
            {

            }
            else//para el caso en que sea un heredoc
            {

            }
//            rellenarlo con la info de los tmp
            //anyadir el nodo a la lista comm lstadd_back
            //liberar la lista de los tokens
            tmp = tmp->next;
            
        }
    }
    //FUNCION QUE LIBERA TODOS LOS TOKENS UNA VEZ QUE YA LOS TENEMOS EN LA LISTA comm
}
/* NOTAS PARA PARSER:
Si el operador es > o >>, lo siguiente ha de ser un redireccionador de salida (fd_out).
si el operador es <, lo siguiente sera un redireccionador de entrada (fd_in).
si el operador es << (heredoc) lo siguiente sera una marca EOF que esperará un input. Esto supongo lo hemos de gestionar aparte.
*/