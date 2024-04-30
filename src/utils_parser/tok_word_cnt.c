#include "minishell.h"

/*OJO, DE MOMENTO NO SE USA*/
/*---Cuenta el num de WORD de una lista t_lst----*/
size_t tok_word_cnt(t_lst *tokens)
{
    t_lst   *aux;
    size_t  cnt;

    aux = tokens;
    cnt = 0;
    while (aux && aux->key != PIPE)
    {
        if (aux->key == WORD)
            cnt++;
        aux = aux->next;
    }
    return (cnt);
}