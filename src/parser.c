#include "minishell.h"


int	parser(t_cmd **cmd, t_tok *tok)
{
	t_cmd   *node;
    t_tok   *tmp;
    size_t  i;
    size_t  size;
    t_redir *node_redir;

    node = NULL;
    tmp = NULL;
    size = 0;
    node_redir = NULL;
    tmp = tok_last(tok);//puntero al ultimo token de la lista
//  FILTRADO DE ERRORES SINTACTICOS
    if (tok->type == PIPE || tmp->type == PIPE)//SI EMPIEZA O ACABA EN '|'
    {
        handle_error(PRINT_SYNTAX_ERR_1, &tok);//printa error y libera tok
        return (1);
    }
    if (is_operator(tmp))//SI ACABA EN OPERADOR <,>,<<,>>,| = SYNTAX_ERROR
    {
        handle_error(PRINT_SYNTAX_ERR_2, &tok);//printa error y libera tok
        return (1);
    }
    tmp = tok;//lo reinicializo al inicio de lista tok
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>operator_syntax_check(tok);
    while (tmp)
    {
        if (is_operator(tmp) && is_operator(tmp->next))//SI DESPUES DE OPERADOR HAY OTRO OPERADOR = SYNTAX_ERROR
        {
            handle_error(PRINT_SYNTAX_ERR_3, &tok);//printa error y libera tok
            return (1);
        }
        tmp = tmp->next;
    }
//  AQUI DEBERIA VOLVER A APUNTAR tmp A tok
    tmp = tok;
//------------CREA LA LISTA t_cmd CON CADA PIPE--------
    while (tmp && tmp->type != NULL_TYPE)//Es necesario NULL_TYPE?
    {
        node = cmd_new_node();//crea un nodo t_cmd mallocado con todos sus elementos a NULL
        i = 0;        
        size = commands_size(tmp);//averigua el size que debera tener el array de commands
//        printf("size de commands: %zu\n", size);
        if (size > 0)//solo se crea/malloca **commands si existe algun comando 
            node->commands = (char **)p_malloc((size + 1) * sizeof(char *));
         while (tmp && tmp->type != NULL_TYPE)//Inicializa el nodo t_cmd con el pipe actual
        {
//            if (is_operator(tmp) && tmp->next->type != WORD)//si es operador y siguiente NO es WORD
//            {
//                handle_error(PRINT_SYNTAX_ERR_3, &tok);//printa error y libera tok
//                cmd_free(&node);//libero el nodo cmd y la matriz command que acabo de mallocar, porque no llegara al free del minishell
////                tok_free(&tok);
//                if (cmd != NULL)
//                    cmd_free(cmd);
//                return (1);
//            }
            if (tmp->type == WORD)
            {
                node->commands[i] = ft_strdup(tmp->str);//duplica la WORD y la mete en char** de t_cmd
                i++;                if (i == size)
                    node->commands[i] = NULL;//cierro el array con NULL si es el ultimo elemento
                tmp = tmp->next;
            }
            else if (is_redirection(tmp) && tmp->next->type == WORD)//SI ES REDIRECCION Y NEXT ES WORD
            {
                node_redir = redir_new_node(ft_strdup(tmp->next->str), tmp->type - 2);//crea e inicializa node t_redir
                redir_add_back(&node->redir, node_redir);
                tmp = tmp->next->next;//salto dos nodos de tok (operador + key)
            }
            else if (tmp->type == PIPE)//si es pipe YYYYYYYYY el next NO es un PIpe
            {
                tmp = tmp->next;
                break;
            }
        }
        cmd_add_back(cmd, node);
    }
    //print_cmd(*cmd);
    return (0);
}