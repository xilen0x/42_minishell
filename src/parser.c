#include "minishell.h"

void    parser(t_cmd **cmd, t_tok *tok)//afegir un int *exit per recollir l'exit_status de la funcio
{
    t_cmd   *node;
    t_tok   *tmp;
    size_t  i;
    size_t  size;
    t_redir *node_file_io;


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
        //cuenta WORDS y OPERATORS del pipe actual y crea **command con tamaño correspondiente        
        size = command_size(tok);
        node->command_and_arguments = (char **)malloc((size + 1) * sizeof(char *));
//>>>>FALTA INCLUIR FUNCIONES EN .h Y REVISAR QUE NUEVA STRUCTURA t_redir ESTE BIEN IMPLANTADA<<<<<
        //Inicializa las variables del pipe/node actual
        while (tmp && tmp->type != NULL_KEY && tmp->type != PIPE)
        {
            if (is_operator(tok->type) && tok->next->type != WORD)//si es operador y siguiente no es WORD
            {
                handle_error(PRINT_SYNTAX_ERR_3, &tok); //h
                return;//ARREGLAR
            }
            if (tmp->type == WORD)
            {
                node->command_and_arguments[i] = ft_strdup(tmp->str);//rellena matriz
                i++;
                if (i == size)
                    node->command_and_arguments[i] = '\0';
                tmp = tmp->next;
            }
            else if (is_operator(tmp->type) /* h */&& tmp->next->type == WORD)
            {
                node_file_io = tok_new_node(ft_strdup(tmp->next->str), tmp->type);
                tok_add_back(node->io_redirect_list, node_file_io);
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
*/