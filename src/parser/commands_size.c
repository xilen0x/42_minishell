#include "minishell.h"

/* Counts the number of 'commands' in the current pipe */
size_t commands_counter(t_tok *tok)
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
        || aux->type == D_GREATER || aux->type == D_SMALLER)
            cnt2++;
        aux = aux->next;
    }
    return (cnt1 - cnt2);
}