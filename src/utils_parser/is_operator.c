#include "minishell.h"

/*Returns TRUE if 'node' contains '<', '>', '<<' or '>>', FALSE otherwise.*/

int	is_operator(t_tok *node)
{
	if (node->type == GREATER || node->type == SMALLER \
    || node->type == DOUBLE_GREATER || node->type == DOUBLE_SMALLER)
		return (TRUE);
	return (FALSE);
}
