#include "minishell.h"

void    parser(t_cmd **cmd, t_tok *tok)//afegir un int *exit per recollir l'exit_status de la funcio
{
    t_cmd   *node;
    t_tok   *tmp;
    size_t  i;
    size_t  size;
    t_redir *node_redir;
    t_redir **redir;//quizas deberia venir en la t_global


    tmp = tok_last(tok);//puntero al ultimo token de la lista

//-----PROTECTORES PARA DESCARTAR ERRORES GRAMATICALES BASICOS EN LA LINEA---------
 
    if (tok->type == PIPE || tmp->type == PIPE)//si linea comienza o acaba en '|'
    {
        handle_error(PRINT_SYNTAX_ERR_1, &tok);
        return;
    }
    if (is_operator(tmp->type))//si linea acaba en operador <,>,<<,>>
    {
        handle_error(PRINT_SYNTAX_ERR_2, &tok); //h
        return;//ARREGLAR
    }
    tmp = tok;//lo reinicializo al inicio de tok
    //recorre lista 'tmp' y crea un nodo 'cmd' para cada pipe.
    while (tmp && tmp->type != NULL_KEY)
    {
        node = cmd_new_node(); 
        i = 0;
        //cuenta WORDS y OPERATORS del pipe actual y crea **command_and_arg con el tamaño correspondiente        
        size = command_and_arg_size(tok);
        node->command_and_arg = (char **)malloc((size + 1) * sizeof(char *));
//>>>>FALTA REVISAR QUE NUEVA STRUCTURA t_redir ESTE BIEN IMPLANTADA<<<<<
        //Inicializa las variables del pipe/node actual
        while (tmp && tmp->type != NULL_KEY && tmp->type != PIPE)
        {
            if (is_operator(tok->type) && tok->next->type != WORD)//si es operador y siguiente no es WORD
            {
                handle_error(PRINT_SYNTAX_ERR_3, &tok);
                return;//ARREGLAR
            }
            if (tmp->type == WORD)
            {
                node->command_and_arg[i] = ft_strdup(tmp->str);//rellena matriz
                i++;
                if (i == size)
                    node->command_and_arg[i] = '\0';
                tmp = tmp->next;
            }
            else if (is_operator(tmp->type) && tmp->next->type == WORD)//si es operador + WORD, lo mete en un nodo redir
            {
                node_redir = redir_new_node(ft_strdup(tmp->next->str), tmp->type);//cambiar GREATER por REDIR_OUTPUT ??
                free(LIBERAR EL STR >>>>>>>>>>>>>>>>>>>>>>>>)
                redir_add_back(redir, node_redir);
                tmp = tmp->next->next;//salto dos nodos de tok (operador + key)
            }
        }
        tok_add_back(cmd, node);
    }
    tok_free(tok);
}
/* NOTAS PARA PARSER:
Si el operador es > o >>, lo siguiente ha de ser un file de salida (fd_out).
si el operador es <, lo siguiente sera un file de entrada (fd_in).
si el operador es << (heredoc) lo siguiente sera una WORD (marca EOF) que esperará un input. Esto supongo lo hemos de gestionar aparte.
HACER UN FREE_GLOBAL QUE LIBERE Y LIMPIE CADA LISTA SI EXISTE
*/