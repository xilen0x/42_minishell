#include "minishell.h"

void    parser(t_cmd **cmd, t_lst *tokens)//afegir un int *exit per recollir l'exit_status de la funcio
{
    t_cmd   *node;
    t_lst   *tmp;
    size_t  i;
    size_t  size;
    t_redir   *node_fd_io;


    tmp = lst_last(tokens);//puntero al ultimo token de la lista

//-----PROTECTORES PARA DESCARTAR ERRORES GRAMATICALES BASICOS EN LA LINEA---------
 
    if (tokens->key == PIPE || tmp->key == PIPE)//si linea comienza o acaba en '|'
    {
        handle_error(PRINT_SYNTAX_ERR_1, &tokens); //h
        return;
    }
    if (is_operator(tmp->key))//si linea acaba en operador <,>,<<,>>
    {
        handle_error(PRINT_SYNTAX_ERR_2, &tokens); //h
        return;//ARREGLAR
    }
    tmp = tokens;//lo reinicializo al inicio de tokens
    //recorre lista 'tmp' y crea un nodo 'cmd' para cada pipe.
    while (tmp && tmp->key != NULL_KEY)
    {
        node = cmd_new_node(); 
        i = 0;
        //cuenta WORDS y OPERATORS del pipe actual y crea **cmd_arg con tamaño correspondiente        
        size = cmd_arg_size(tokens); //h
        node->cmd_arg = (char **)malloc((size + 1) * sizeof(char *));
//>>>>FALTA INCLUIR FUNCIONES EN .h Y REVISAR QUE NUEVA STRUCTURA t_redir ESTE BIEN IMPLANTADA<<<<<
        //Inicializa las variables del pipe/node actual
        while (tmp && tmp->key != NULL_KEY && tmp->key != PIPE)
        {
            if (is_operator(tokens->key) && tokens->next->key != WORD)//si es operador y siguiente no es WORD
            {
                handle_error(PRINT_SYNTAX_ERR_3, &tokens); //h
                return;//ARREGLAR
            }
            if (tmp->key == WORD)
            {
                node->cmd_arg[i] = ft_strdup(tmp->val);//rellena matriz
                i++;
                if (i == size)
                    node->cmd_arg[i] = '\0';
                tmp = tmp->next;
            }
            else if (is_operator(tmp->key) /* h */&& tmp->next->key == WORD)
            {
                node_fd_io = lst_new_node(ft_strdup(tmp->next->val), tmp->key);
                lst_add_back(node->fd_io, node_fd_io);
                tmp = tmp->next->next;//salto dos nodos de tokens (operador + key)
            }
        }
        lst_add_back(cmd, node);
    }
    //LIBERAR t_lst *tokens UNA VEZ PASADOS TODOS A t_cmd *cmd
    lst_clear(tokens);
}
/* NOTAS PARA PARSER:
Si el operador es > o >>, lo siguiente ha de ser un file de salida (fd_out).
si el operador es <, lo siguiente sera un file de entrada (fd_in).
si el operador es << (heredoc) lo siguiente sera una WORD (marca EOF) que esperará un input. Esto supongo lo hemos de gestionar aparte.
*/