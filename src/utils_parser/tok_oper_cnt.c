#include "minishell.h"

/* OJO, DE MOMENTO NO SE USA*/
size_t tok_oper_cnt(t_lst *tokens)
{
    t_lst   *aux;
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