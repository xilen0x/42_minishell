#include "minishell.h"

/*Returns '1' if a syntax error on the list is found, otherwise returns 0.*/
int	syntax_check_1(t_tok *tok)
{
	t_tok	*tmp;

	tmp = tok_last(tok);//puntero al ultimo token de la lista
	if (tok->type == PIPE || tmp->type == PIPE)//SI EMPIEZA O ACABA EN '|'
	{
	    handle_error(PRINT_SYNTAX_ERR_1, &tok);//printa error y libera tok
	    return (1);
	}
	if (is_operator(tmp))//SI ACABA EN OPERADOR <,>,<<,>>,|
	{
	    handle_error(PRINT_SYNTAX_ERR_2, &tok);//printa error y libera tok
	    return (1);
	}
	return (0);
}