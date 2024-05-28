#include "minishell.h"

/*Returns TRUE if 'node' contains '<', '>', '<<', '>>' or '|' 
or FALSE otherwise.*/

int	is_operator(t_tok *node)
{
	if (node->type == GREATER || node->type == SMALLER \
    || node->type == D_GREATER || node->type == D_SMALLER \
	|| node->type == PIPE)
		return (TRUE);
	return (FALSE);
}