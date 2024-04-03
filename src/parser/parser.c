#include "minishell.h"

void    parser(t_cmd **cmd, t_tok *tok)//afegir un int *exit_status per recollir l'exit_status de la funcio
{
    t_cmd   *node;
    t_tok   *tmp;
    size_t  i;
    size_t  size;
    t_redir *node_redir;
//    t_redir **redir = NULL;//NO SE SI ES NECESARIO


    tmp = tok_last(tok);//puntero al ultimo token de la lista

//-----PROTECTORES PARA DESCARTAR ERRORES GRAMATICALES BASICOS EN LA LINEA---------
 
    if (tok->type == PIPE || tmp->type == PIPE)//si linea comienza o acaba en '|'
    {
        handle_error(PRINT_SYNTAX_ERR_1, &tok);
        return;
    }
    if (is_operator(tmp))//si linea acaba en operador <,>,<<,>>
    {
        handle_error(PRINT_SYNTAX_ERR_2, &tok); //h
        return;//ARREGLAR
    }
    tmp = tok;//lo reinicializo al inicio de lista tok
    //recorre lista de tokens y crea un nodo 't_cmd' para cada pipe.
    while (tmp && tmp->type != NULL_TYPE)
    {
        node = cmd_new_node();//crea nodo t_cmd
        i = 0;        
        size = command_and_arg_size(tok);//averigua el size que debera tener la matriz
        node->command_and_arg = (char **)malloc((size + 1) * sizeof(char *));
//        while (tmp && tmp->type != NULL_TYPE && tmp->type != PIPE)//Inicializa el nodo t_cmd con el pipe actual
        while (tmp && tmp->type != NULL_TYPE)//Inicializa el nodo t_cmd con el pipe actual
        {
            if (is_operator(tok) && tok->next->type != WORD)//si es operador y siguiente no es WORD
            {
                handle_error(PRINT_SYNTAX_ERR_3, &tok);
                return;//ARREGLAR
            }
            if (tmp->type == WORD)
            {
                node->command_and_arg[i] = ft_strdup(tmp->str);//rellena matriz
                i++;
                if (i == size)
                    node->command_and_arg[i] = NULL;
                tmp = tmp->next;
            }
            else if (is_operator(tmp) && tmp->next->type == WORD)//si es operador y next es WORD
            {
                node_redir = redir_new_node(ft_strdup(tmp->next->str), tmp->type);//crea e inicializa node t_redir
                redir_add_back(&node->redir, node_redir);
                tmp = tmp->next->next;//salto dos nodos de tok (operador + key)
            }
            else if (tmp->type == PIPE)
            {
                tmp = tmp->next;
                break;
            }
        }
        cmd_add_back(cmd, node);
    }
    cmd_print(*cmd);
//    cmd_free(cmd);
//    tok_free(&tok);//liberar TODO t_tok una vez acabado el parser
}
/* NOTAS PARA MAS ADELANTE:
si t_redir contiene un << (heredoc) su WORD sera una marca EOF que esperará un input. 
Lo hemos de gestionar despues del parser.
HACER UN FREE_GLOBAL QUE LIBERE Y LIMPIE CADA LISTA SI EXISTE
*/