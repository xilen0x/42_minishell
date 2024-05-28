#include "minishell.h"

/*OJO, DE MOMENTO NO SE USA*/
/*-Counts the num of WORD on a list are found-*/
size_t tok_word_cnt(t_tok *tokens)
{
    t_tok   *aux;
    size_t  cnt;

    aux = tokens;
    cnt = 0;
    while (aux && aux->type != PIPE)
    {
        if (aux->type == WORD)
            cnt++;
        aux = aux->next;
    }
    return (cnt);
}