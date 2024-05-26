#include "minishell.h"

/*Returns '1' if 'tok' list contain an operator next to another operator*/
int	syntax_check_2(t_tok *tok)
{
	t_tok	*tmp;

	tmp = tok;
	while (tmp)
    {
        if (is_operator(tmp) && is_operator(tmp->next))//SI DESPUES DE UN OPERADOR HAY OTRO OPERADOR
        {
            handle_error(PRINT_SYNTAX_ERR_3, &tok);//printa error y libera tok
            return (1);
        }
        tmp = tmp->next;
    }
	return (0);
}