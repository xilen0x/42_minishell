#include "minishell.h"

/*Returns TRUE if 'node' contains '<', '>', '<<', '>>' or '|' and FALSE otherwise.*/

int	is_operator(t_tok *node)
{
	if (node->type == GREATER || node->type == SMALLER \
    || node->type == DOUBLE_GREATER || node->type == DOUBLE_SMALLER \
	|| node->type == PIPE)
		return (TRUE);
	return (FALSE);
}
