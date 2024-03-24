#include "minishell.h"

static void init_node(t_comm *node, t_lst *tokens)
{
    node->index = 0;
    node->tokens = tokens;
    node->command = NULL;
    node->comm_arg = NULL;
    node->fd_in = NULL;
    node->fd_out = NULL;
    node->is_builtin = 0;
}

void    parser(t_comm comm, t_lst *tokens)//deberia recoger y devolver si hay un fallo sintactico
{
    t_comm  *node;

    //ANTES QUE NADA, CHECK DE REGLAS SINTACTICAS BASICAS
    if (!tokens && tokens->key == NULL_KEY)//protector, hace falta?
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
    while (tokens && tokens->key != NULL_KEY && tokens->key != PIPE)
//        t_lst   aux;//creo que no lo necesito para recorrer la lista
    {//ANTES DE NADA, SEPARAR POR PIPELINES
        node = (t_comm *)malloc(sizeof(t_comm));//asigno memoria a un nodo
        init_node(node, tokens);//inicializo el contenido del nodo con tokens y el resto a NULL
        //habra una funcion que mirara si WORD es un builtin
        rellenarlo con la info de los tokens
    }

}
/* NOTAS PARA PARSER:
Si el operador es > o >>, lo siguiente ha de ser un redireccionador de salida (fd_out).
si el operador es <, lo siguiente sera un redireccionador de entrada (fd_in).
si el operador es << (heredoc) lo siguiente sera una marca EOF que esperará un input. Esto supongo lo hemos de gestionar aparte.
*/