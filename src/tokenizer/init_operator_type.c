#include "minishell.h"

/*--Initializes t_tok->type if an operator (<, <<, >, >>, |) is found.--*/
int	init_operator_type(char *line, t_tok **new_tok)
{
	int	flag;

	flag = 1;
	if (*line == '>' && *line == *(line + 1))
		(*new_tok)->type = DOUBLE_GREATER;
	else if (*line == '<' && *line == *(line + 1))
		(*new_tok)->type = DOUBLE_SMALLER;	
	else if (*line == '>')
		(*new_tok)->type = GREATER;
	else if (*line == '<')
		(*new_tok)->type = SMALLER;
	else if (*line == '|')
		(*new_tok)->type = PIPE;
	else
		flag = 0;
	return (flag);
}