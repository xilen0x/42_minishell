#include "minishell.h"

/*Returns '1' if two consecutive operators on the list are found, otherwise 
returns 0*/
int	syntax_check_2(t_tok *tok)
{
	t_tok	*tmp;

	tmp = tok;
	while (tmp)
    {
        if (is_operator(tmp) && is_operator(tmp->next))//si dos operador juntos
        {
            handle_error(PRINT_SYNTAX_ERR_3, &tok);//printa error y libera tok
            return (1);
        }
        tmp = tmp->next;
    }
	return (0);
}