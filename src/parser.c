#include "minishell.h"

void	parser(t_cmd **cmd, t_tok *tok)
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
    if (tok->type == PIPE || tmp->type == PIPE)//si linea comienza o acaba en '|'
    {
        handle_error(PRINT_SYNTAX_ERR_1, &tok);
        return;//OJO: GESTIONAR ESTA SALIDA
    }
    if (is_operator(tmp))//si linea acaba en operador <,>,<<,>>
    {
        handle_error(PRINT_SYNTAX_ERR_2, &tok);
        return;//OJO: GESTIONAR ESTA SALIDA
    }
    tmp = tok;//lo reinicializo al inicio de lista tok
    while (tmp && tmp->type != NULL_TYPE)//recorre lista t_tok y crea lista t_cmd con cada PIPE
    {
        node = cmd_new_node();//crea nodo t_cmd
        i = 0;        
        size = commands_size(tmp);//averigua el size que debera tener la matriz
        node->commands = (char **)p_malloc((size + 1) * sizeof(char *));
         while (tmp && tmp->type != NULL_TYPE)//Inicializa el nodo t_cmd con el pipe actual
        {
            if (is_operator(tmp) && tmp->next->type != WORD)//si es operador y siguiente no es WORD
            {
                handle_error(PRINT_SYNTAX_ERR_3, &tok);
                return;//OJO: GESTIONAR ESTA SALIDA
            }
            if (tmp->type == WORD)
            {
                node->commands[i] = ft_strdup(tmp->str);//duplica la WORD y la mete en char** de t_cmd
                i++;
                if (i == size)
                    node->commands[i] = NULL;//cierro el array con NULL si es el ultimo elemento
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
    //print_cmd(*cmd);
}