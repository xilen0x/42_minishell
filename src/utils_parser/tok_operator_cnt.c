#include "minishell.h"

/* OJO, DE MOMENTO NO SE USA*/
/*----Counts the num of redirection operators in a t_lst list---*/
size_t tok_operator_cnt(t_tok *tokens)
{
    t_tok   *aux;
    size_t  cnt;

    aux = tokens;
    cnt = 0;
    while (aux && aux->key != PIPE)
    {
        if (aux->key == GREATER || aux->key == SMALLER \
        || aux->key == D_GREATER || aux->key == D_SMALLER)
            cnt++;
        aux = aux->next;
    }
    return (cnt);
}