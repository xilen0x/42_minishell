#include "minishell.h"

/* cuenta los command_and_arguments (num de WORD - num de OPERATORS) del pipe actual en la lista 't_tok'*/
size_t command_size(t_tok *tok)
{
    t_tok   *aux;
    size_t  cnt1;
    size_t  cnt2;

    aux = tok;
    cnt1 = 0;
    cnt2 = 0;
    while (aux && aux->type != PIPE)
    {
        if (aux->type == WORD)
            cnt1++;
        if (aux->type == GREATER || aux->type == SMALLER \
        || aux->type == DOUBLE_GREATER || aux->type == DOUBLE_SMALLER)
            cnt2++;
        aux = aux->next;
    }
    return (cnt1 - cnt2);
}