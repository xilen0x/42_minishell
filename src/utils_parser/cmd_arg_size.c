#include "minishell.h"

/* cuenta los command (num de WORD - num de OPERATORS) de la lista tokens*/
size_t cmd_arg_size(t_tok *tokens)
{
    t_tok   *aux;
    size_t  cnt1;
    size_t  cnt2;

    aux = tokens;
    cnt1 = 0;
    cnt2 = 0;
    while (aux && aux->key != PIPE)
    {
        if (aux->key == WORD)
            cnt1++;
        if (aux->key == GREATER || aux->key == SMALLER \
        || aux->key == D_GREATER || aux->key == D_SMALLER)
            cnt2++;
        aux = aux->next;
    }
    return (cnt1 - cnt2);
}