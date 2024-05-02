#include "minishell.h"

void    parser(t_cmd **cmd, t_tok *tok)
{
    t_cmd   *node;
    t_tok   *tmp;
    size_t  i;
    size_t  size;
    t_redir *node_redir;

    node = NULL;
    tmp = NULL;
//    i = 0;
    size = 0;
    node_redir = NULL;
    tmp = tok_last(tok);//puntero al ultimo token de la lista
    if (tok->type == PIPE || tmp->type == PIPE)//si linea comienza o acaba en '|'
    {
        handle_error(PRINT_SYNTAX_ERR_1, &tok);
        return;
    }
    if (is_operator(tmp))//si linea acaba en operador <,>,<<,>>
    {
        handle_error(PRINT_SYNTAX_ERR_2, &tok);
        return;//ARREGLAR
    }
    tmp = tok;//lo reinicializo al inicio de lista tok
    //recorre lista de tokens y crea un nodo 't_cmd' para cada pipe.
    while (tmp && tmp->type != NULL_TYPE)
    {
        node = cmd_new_node();//crea nodo t_cmd
        i = 0;        
        size = command_and_arg_size(tmp);//averigua el size que debera tener la matriz
        node->command_and_arg = (char **)malloc((size + 1) * sizeof(char *));
//        if (node->command_and_arg == NULL)
//      {
//            printf("Memory allocation failed (malloc)\n");
//            exit (EXIT_FAILURE);
//        }
        malloc_d_pointer_protect(node->command_and_arg);//es el protector del malloc
        while (tmp && tmp->type != NULL_TYPE)//Inicializa el nodo t_cmd con el pipe actual
        {
            if (is_operator(tmp) && tmp->next->type != WORD)//si es operador y siguiente no es WORD
            {
                handle_error(PRINT_SYNTAX_ERR_3, &tok);
                return;//ARREGLAR
            }
            if (tmp->type == WORD)//si es palabra
            {
                node->command_and_arg[i] = ft_strdup(tmp->str);//rellena matriz
                i++;
                if (i == size)
                    node->command_and_arg[i] = NULL;//cierro el array con NULL en el ultimo elemento
                tmp = tmp->next;
            }
            else if (is_operator(tmp) && tmp->next->type == WORD)//si es operador y next es WORD
            {
                node_redir = redir_new_node(ft_strdup(tmp->next->str), tmp->type);//crea e inicializa node t_redir
                redir_add_back(&node->redir, node_redir);
                tmp = tmp->next->next;//salto dos nodos de tok (operador + key)
            }
            else if (tmp->type == PIPE)//si es pipe
            {
                tmp = tmp->next;
                break;
            }
        }
        cmd_add_back(cmd, node);
    }
    print_cmd(*cmd);
//    tok_free(&tok);//liberar TODO t_tok una vez acabado el parser
}