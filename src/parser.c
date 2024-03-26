#include "minishell.h"

void    parser(t_cmd **cmd, t_lst *tokens)
{
    t_cmd           *node;
    t_lst           *tmp;
    unsigned int    i;

    tmp = lst_last(tokens);//puntero al ultimo token de la lista

//-----PROTECTORES PARA DESCARTAR ERRORES GRAMATICALES BASICOS EN LA LINEA---------
 
    if (tokens->key == PIPE || tmp->key == PIPE)//si comienza o acaba en '|'
        handle_error(PRINT_SYNTAX_ERR_1, &tokens);
        volver al inicio del bucle de readline, pero como??

    if (is_operator(tmp->key))//si linea acaba en operador <,>,<<,>>
/*    if (tmp->key == GREATER || tmp->key == SMALLER \
    || tmp->key == D_GREATER || tmp->key == D_SMALLER)*/
        return (perror("minishell: syntax error near unexpected token `newline'"));//ARREGLAR

    tmp = tokens;//ahora lo inicializo al inicio de tokens

    //recorre lista 'tmp' y crea un nodo 'cmd' para cada pipe.
    while (tmp && tmp->key != NULL_KEY)
    {
        node = new_cmd_node(); 
        i = 0;
        
        node->cmd_arg = (char **)malloc((tok_word_cnt(tokens) - num de operators + 1) * sizeof(char *));
        contador de WORDS i contador de OPERATORS fins al PIPE(arg puntero tmp al nodo del pipe actual)
        (WORDS - operadores <,>,<<,>>)sabre len de cmd_arg i num de nodos de fd_io

        //Inicializo variables del nodo del pipe actual
        while (tmp && tmp->key != NULL_KEY && tmp->key != PIPE)
        {
            if (is_operator(tokens->key) && tokens->next->key != WORD)//si es operador y next NO es WORD
                return (perror("minishell: syntax error near unexpected token `newline'"));//ARREGLAR

            if (tmp->key == WORD)
            {
                node->cmd_arg[i] = ft_strdup(tmp->val);//relleno matriz
                i++;
                tmp = tmp->next;
            }
            else if (is_operator(tmp->key) && tmp->next->key == WORD)//quizas bastaria con un else sin condicion
            {
                node->fd_io->val = ft_strdup(tmp->next->val);
                node->fd_io->key = tmp->key;
                tmp = tmp->next->next;
            }
            lst_add_back(cmd, node);
        }
    }
    //LIBERAR t_lst *tokens UNA VEZ PASADOS TODOS A t_cmd *cmd
}
/* NOTAS PARA PARSER:
Si el operador es > o >>, lo siguiente ha de ser un file de salida (fd_out).
si el operador es <, lo siguiente sera un file de entrada (fd_in).
si el operador es << (heredoc) lo siguiente sera una WORD (marca EOF) que esperará un input. Esto supongo lo hemos de gestionar aparte.
*/