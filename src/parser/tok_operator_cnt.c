#include "minishell.h"

/* OJO, DE MOMENTO NO SE USA*/
/*----Counts the num of redirection operators in a t_lst list---*/
size_t tok_operator_cnt(t_tok *tokens)
{
    t_tok   *aux;
    size_t  cnt;

    aux = tokens;
    cnt = 0;
    while (aux && aux->type != PIPE)
    {
        if (aux->type == GREATER || aux->type == SMALLER \
        || aux->type == DOUBLE_GREATER || aux->type == DOUBLE_SMALLER)
            cnt++;
        aux = aux->next;
    }
    return (cnt);
}